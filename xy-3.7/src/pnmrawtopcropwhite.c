/* $Id: pnmrawtopcropwhite.c,v 3.7 1999/02/16 15:12:50 krisrose Exp $
**
** Crop off top white lines from raw PBM file (efficiently :)
** Copyright (c) 1991-1998	 Kristoffer H. Rose  <krisrose@brics.dk>
**
** This file is part of the Xy-pic package for graphs and diagrams in TeX.
** Copyright (c) 1991-1998	 Kristoffer H. Rose  <krisrose@brics.dk>
**
** The Xy-pic package is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by the
** Free Software Foundation; either version 2 of the License, or (at your
** option) any later version.
**
** The Xy-pic package is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
** or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU General Public License
** for more details.
**
** You should have received a copy of the GNU General Public License along
** with this package; if not, write to the Free Software Foundation, Inc.,
** 675 Mass Ave, Cambridge, MA 02139, USA.
*/
static const char Id[] =
"@(#)$Id: pnmrawtopcropwhite.c,v 3.7 1999/02/16 15:12:50 krisrose Exp $\n";


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Globals */

#define PBMRAWMAGIC "P4"	/* Portable BitMap magic cookie */
#define PGMRAWMAGIC "P5"	/* Portable GrayMap magic cookie */
#define PPMRAWMAGIC "P6"	/* Portable PixMap magic cookie */
#define MAGICSIZE 2

static char *me;		/* program name */

/* Subroutines */

void oops(void) {
  fprintf(stderr, "Usage: %s\n", me);
  exit(1);
}

void panic(const char *mess) {
  fprintf(stderr, "Error: %s\nUsage: %s\n", mess, me);
  exit(2);
}

void skipcomment(void) {
  int c;
  while(1) {
    switch (c = getchar()) {
     case EOF: panic("premature EOF on input"); break;
     case '\n': return;
     default: break;
    }
  }
}

void skipwhite(void) {
  int c;
  while(1) {
    switch (c = getc(stdin)) {
     case EOF: panic("premature EOF on input"); break;
     case ' ': case '\t': case '\r': case '\n': break;
     case '#': skipcomment(); break;
     default: ungetc(c, stdin); return;
    }
  }
}

int nextint(const char *what) {
  int i;
  skipwhite();
  if (!scanf("%d", &i)) panic(what);
  return i;
}

/* Program */

int main (int argc, char *argv[]) {

  char magic[MAGICSIZE];
  enum { PBM, PGM, PPM } which;
  int width, height, newheight, pixelmax;

  int linelength;
  char *line, *whiteline;

  /* establish identity and proper usage */
  me = argv[0];
  if (argc != 1) oops();

  /* magic */
  if (!fread(magic, 1, MAGICSIZE, stdin))
    panic("no magic (nothing on standard input)");

  if (!memcmp(magic, PBMRAWMAGIC, MAGICSIZE))
    which = PBM;
  else if (!memcmp(magic, PGMRAWMAGIC, MAGICSIZE))
    which = PGM;
  else if (!memcmp(magic, PPMRAWMAGIC, MAGICSIZE))
    which = PPM;
  else
    panic("bad magic (standard input not a raw anymap)");

  /* width and height */
  width = nextint("pixelwidth integer");
  height = nextint("pixelheight integer");
  switch (which) {
   case PBM: pixelmax = 0; break; /* hack (used by memset below) */
   case PGM: case PPM:
    pixelmax = nextint("pixelmax integer");
    if (pixelmax > 255) panic("pixelmax larger than 255");
  }
  if (getchar() != '\n')
    panic("something not a simple newline after width height [pixelmax]");

  /* allocate pixel line */
  switch (which) {
   case PBM: linelength = (width + 7) / 8; break;
   case PGM: linelength = width; break;
   case PPM: linelength = width * 3; break;
  }
  line = (char*)malloc(linelength);
  if (!line) panic("could not allocate pixel line");
  whiteline = (char*)malloc(linelength);
  if (!whiteline) panic("could not allocate white pixel line");
  memset(whiteline, pixelmax, linelength);

  /* skip white pixel lines */
  newheight = height;
  while (fread(line, linelength, 1, stdin)
	 && !memcmp(line, whiteline, linelength)) {
    newheight--;
    if (newheight <= 0) panic("entire image blank");
  }

  /* output revised header */
  if (newheight < height)
    fprintf(stderr,"%s: cropping %d rows off the top\n", me, height-newheight);
  printf("%.*s\n%d %d\n", MAGICSIZE, magic, width, newheight);
  switch (which) {
   case PBM: break;
   case PGM: case PPM:
    printf("%d\n", pixelmax); break;
  }

  /* output remainder of image */
  do {
    if (!fwrite(line, linelength, 1, stdout)) panic("could not write");
  } while (fread(line, linelength, 1, stdin));
  if (!feof(stdin)) panic("input not exhausted");
  
  return(0);
}


/*
** $Log: pnmrawtopcropwhite.c,v $
** Revision 3.7  1999/02/16 15:12:50  krisrose
** Interim release (Y&Y fonts now free).
**
** Revision 1.3  1997/05/01 20:59:51  krisrose
** Works for all three raw formats now.
**
** Revision 1.2  1997/05/01 17:34:58  krisrose
** Extended to raw PGM and PPM in addition to PBM.
**
** Revision 1.1  1997/04/30 21:30:31  krisrose
** Initial revision
*/

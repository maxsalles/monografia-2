# $Id: Makefile,v 3.7 1999/02/16 15:12:50 krisrose Exp krisrose $
#
# Un*x Makefile for Xy-pic macros, fonts, documentation, and distribution.
# Copyright (c) 1991-1997  Kristoffer H. Rose  <krisrose@ens-lyon.fr>
#
# This file is part of the Xy-pic macro package.
# Copyright (c) 1991-1997  Kristoffer H. Rose  <krisrose@ens-lyon.fr>
# See the README and INSTALL files for further information.
#
# The Xy-pic package is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# The Xy-pic package is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License along
# with this package; if not, write to the Free Software Foundation, Inc.,
# 675 Mass Ave, Cambridge, MA 02139, USA.

VERSION = 3.7
SHORTVERSION = 37

# CONTENTS:
#
#   Configuration section:
#	Directories.
#	Fonts.
#	Programs.
#
#   Generic targets.
#   Macros.
#   PostScript headers.
#   Fonts.
#   Formats.
#   Manual: User's guide and reference manual.
#   Reference manual.
#   TeXnical documentation.
#   Distribution tree.
#   Ftp'able distribution.
#   WWW publicity.
#   Announcements.
#   Tags.
#   RCS stuff.
#   Development targets.
#
#   Log.


#### CONFIGURATION SECTION ##################################################

# Please configure as instructed below for each of the DIRECTORIES, FONTS,
# and PROGRAMS parts by editing the definitions to fit your system.

#### DIRECTORIES.
#
# The following variables define the directories where the various parts of
# Xy-pic should be installed.
#
# You should *EITHER* set TDSROOT to the root of a TDS-compliant directory
# tree, usually named .../texmf (if you have a TDS [TeX Directory Structure]
# compliant system then that is in fact all you need to do):
#
USR = /usr/local
TDSROOT = $(USR)/share/texmf
#
# *OR* you should set each of the following variables right for you system
# (do this if your setup does not match TDS exactly):
#
TEXINPUTDIR = $(TDSROOT)/tex/generic/xypic
TEXFONTDIR = $(TDSROOT)/fonts/tfm/public/xypic
TEXDOCDIR = $(TDSROOT)/doc/generic/xypic
MFINPUTDIR = $(TDSROOT)/fonts/source/public/xypic
TYPE1DIR = $(TDSROOT)/fonts/type1/public/xypic
PFMDIR = $(TDSROOT)/fonts/pfm/public/xypic
AFMDIR = $(TDSROOT)/fonts/afm/public/xypic
PDFDIR = $(TDSROOT)/pdftex/xypic
PSHEADERDIR = $(TDSROOT)/dvips/xypic
#
# FONTDIR is the directory where bitmap fonts are stored and is special
# (If you do not plan to install bitmap fonts because they are automatically
# generated and remember to set the MAGS variable below to `.' then you may
# ignore this step.)
#
# Since the location of individual fonts sometimes depend on properties of
# the font, you can insert
#
#	$${dpi}		for the font resolution in `Dots Per Inch' (NOT the
#   			device resolution---that should be inserted directly)
#
#	$${mode}	for the METAFONT `mode' used to generate the font
#
# ---what these get set to depends on the next section.
#
# For example, if you set FONTDIR=/usr/lib/tex/pk$${dpi} and decide in the
# next section to generate PK fonts at 300 dpi using a generic mode
# (localfont) then you get files named /usr/lib/tex/pk300/xy*.300pk.
#
# If your installation still uses the (inefficient) principle of having all
# PK files in the same directory as the TFM files then you should just set
# FONTDIR=$(TEXFONTDIR).
#
FONTDIR = $(TDSROOT)/fonts/pk/$${mode}/public/xypic/dpi$${dpi}

#### FONTS.
#
# The METAFONT program needs to know the `mode' of your printer in order to
# be able to generate correct fonts for it.  On most installations the mode
# `localfont' is made synonymous with the mode required for the default
# printer; in that case you can just pick the `MODES = localfont' line.  If
# this is not the case -- or you need fonts for several output devices---then
# you will have to consult the local METAFONT guide/guru to inquire what
# modes are used at your site.  A good place to look for the modes used is in
# the MakeTeXPK script found on some sites.
#
# Set MODES to the list of printers you wish to use:
#
MODES = localfont
#MODES = cx ljfour
#
# You should also decide which TeX \magsteps you wish the font to be
# generated at.
#
# The default is . (dot) which prevents installation of any bitmaps because
# most modern installations generate them automatically.
#
MAGS = .
#MAGS = 0
#MAGS = 0 0.5 1 2

#### PROGRAMS.
#
# You don't have to edit the following lines unless you have a non-standard
# un*x system or un*x TeX installation...
#
SHELL = /bin/sh
#
TEX = TEXFONTS=.:$(TEXFONTDIR):$$TEXFONTS tex
LATEX = TEXFONTS=.:$(TEXFONTDIR):$$TEXFONTS latex
PDFLATEX = TEXFONTS=.:$(TEXFONTDIR):$$TEXFONTS pdflatex
BIBTEX = BIBINPUTS=. bibtex
MAKEINDEX = makeindex
INITEX = TEXFONTS=.:$(TEXFONTDIR):$$TEXFONTS initex
#
# Set MF to a command that will run plain METAFONT on your system.
#
MF = MFINPUTS=.:$(MFINPUTDIR):$$MFINPUTS mf
#
# Set GFTOPK to the command "false" and PK to "gf" if you use GF rather than PK
# bitmap font files.  There is no support for PXL-files [are they still used?].
# (Note: the default setting of MAGS above doesn't use bitmaps at all.)
#
GFTOPK = gftopk
PK=pk
#
#GFTOPK = false
#PK=gf
#
RM = rm -fr
CP = cp -f
MV = mv -f
#
# Set the INSTALLs to cp -f if your system does not have the install command.
#
INSTALL = install -c -m 444
INSTALLW = install -c -m 644
INSTALLX = install -c -m 555
#INSTALL = cp -f
#INSTALLW = cp -f
#INSTALLX = cp -f
#
# Set MKDIR to a mkdir command that creates intermediate directories.
#
MKDIR = mkdir -p -m 755
#
# DOC2TEX <file>: output efficient .tex file from inefficient .doc <file> with
# inlined documentation [my favourite hack :-].  Removes all DOCMODE lines,
# leaving only things before the first and in DOCMODE(...DOCMODE) brackets;
# also removes all blank lines and comment lines.
#
# If it breaks your sed you can just set DOC2TEX to cat although that will
# make the installed macro files three times larger and the reading of them
# somewhat slower...so in that case you are probably better of getting the
# `run' distribution where this has already been done for you!
#
DOC2TEX = sed \
	-e '/^.DOCMODE(/b Yes' \
	-e '/^.DOCMODE/b No' \
	-e 'x' \
	-e '/%%DONTCOPY%%/b Ignore' \
	-e 'x' \
	-e 's/[ 	][ 	]*/ /g' \
	-e 's/{%.*$$/{%/' -e 's/}%.*$$/}%/' -e 's/ %.*$$//'  \
	-e '/^ *%$$/d' -e '/^ *$$/d' -e '/^ *%[^%]/d' \
	-e 's/^%% \$$Id/%% $@ from $$Id/' \
	-e 's/REPLACEWITHVERSION/$(VERSION)/' \
	-e 's/REPLACEWITHSHORTVERSION/$(SHORTVERSION)/' \
	-e 'b End' \
	-e ': No' -e 's/.*/%%DONTCOPY%%/' -e 'x' -e 'd' \
	-e ': Yes' -e 's/.*//' -e 'x' -e 'd' \
	-e ': Ignore' -e 'x' -e 'd' \
	-e ': End'
#
# MF2TFM script: make .tfm file and all requested bitmap files from .mf
# file by executing METAFONT with $${mode} and $${dpi} as described above.
#
# NOTE: for use as implicit make rule; do not modify unless you are sure you
# need to!
#
MF2TFM = set -x; for mode in $(MODES); do \
	if [ "$(MAGS)" = "." ]; then \
	  $(MF) "\\mode=$$mode; input $<";\
	  $(RM) $*.*gf;\
	else \
	  for mag in $(MAGS); do \
	    $(MF) "\\mode=$$mode; mag=magstep($$mag); input $<"; done;\
	  for f in $*.*gf; do if test -f "$$f"; then \
	    if $(GFTOPK) ./$$f; then $(RM) $$f; fi; else :; fi; done;\
	fi; done

#### END OF CONFIGURATION SECTION ###########################################


# GENERIC TARGETS.
#
all:		macros fonts obsoletefonts
.PHONY:		all install clean realclean sterile world
#
install:	all install.macros install.trailer \
		install.fonts install.obsoletefonts \
		install.ps install.psfonts
#
clean:
	$(RM) *.aux *.toc *.lof *.blg *.log *.idx *.ilg *.fmt \
	  *.ps *.ppm *.nops *.tmp *.ans *.xyc *.xyd \
	  ./#* *~ core *.BAK *JNL xytest.*gf out
#
realclean:	clean
	$(RM) MANIFEST VERSIONS CATALOG
	$(RM) xydoc.back; touch xydoc.back
	$(RM) *.bbl *.glo *.ind \
	  *.tfm *.*gf *.*pk *.tex *.dvips *.dvi *.pdf *.last *.pro \
	  *.gif *.epsf *.size *.pbm *.ppm \
	  *.afm *.pfm *.pfb *.asc
	$(RM) xyguide-html index*
	$(RM) pnmrawtopcropwhite
#
sterile:	realclean rcsclean
	$(RM) xydoc.back make.* TAGS
	$(MAKE) Makefile xydoc.sty xydoc.bib
#
world:		realclean rcsclean
	time $(MAKE) all ftp ftpdoc www 2>&1 |tee make.world


# MACROS.
#
TRAILERSOURCES =	TRAILER COPYING CATALOG.doc \
			MAKE README Makefile $(INSTALLSTAR)

INSTALLSTAR =		INSTALL INSTALL.OzTeX INSTALL.Textures

KERNELSOURCES = 	xy.doc xyidioms.doc xyrecat.doc

OPTIONSOURCES = 	\
	xyframe.doc xycmtip.doc xytips.doc xycurve.doc \
	xyline.doc xyrotate.doc xycolor.doc xycrayon.doc xytile.doc \
	xyimport.doc xytpic.doc xytp-f.doc \
	xyps.doc xyps-ps.doc xyps-pro.doc xyps-col.doc xyps-c.doc xyps-f.doc \
	xyps-l.doc xyps-r.doc xyps-s.doc xyps-t.doc \
	xypsdict.doc xypspatt.doc xydocps.doc \
	xydummy.doc xyall.doc xymatrix.doc xyarrow.doc xygraph.doc \
	xy2cell.doc xypoly.doc xyarc.doc xyknot.doc xyweb.doc \
	xydvips.doc xytextures.doc xy16textures.doc xyoztex.doc xy17oztex.doc \
	xycmactex.doc xydvitops.doc xyemtex.doc xydvidrv.doc xyxdvi.doc \
	xymovie.doc xyv2.doc xypic.doc \
	xynecula.doc xysmart.doc

FORMATSOURCES = 	xytex.ini xylatex.ini

LATEXSTYLES = 		xy.sty xypic.sty movie.cls
OPTIONDATA = 		xymacpat.xyp

MACROSOURCES =		$(TRAILERSOURCES) $(KERNELSOURCES) $(LATEXSTYLES) \
			$(OPTIONSOURCES) $(OPTIONDATA) $(FORMATSOURCES)

TRAILERRUN =		TRAILER COPYING CATALOG README \
			$(INSTALLSTAR) VERSIONS

KERNELRUN =		xy.tex xyidioms.tex xyrecat.tex

OPTIONRUN = 		\
	xyframe.tex xycmtip.tex xytips.tex xycurve.tex \
	xyline.tex xyrotate.tex xycolor.tex xycrayon.tex xytile.tex \
	xyimport.tex xytpic.tex xytp-f.tex \
	xyps.tex xyps-ps.tex xyps-pro.tex xyps-col.tex xyps-c.tex xyps-f.tex \
	xyps-l.tex xyps-r.tex xyps-s.tex xyps-t.tex \
	xypsdict.tex xypspatt.tex $(OPTIONDATA) \
	xydummy.tex xyall.tex xymatrix.tex xyarrow.tex xygraph.tex \
	xy2cell.tex xypoly.tex xyarc.tex xyknot.tex xyweb.tex \
	xydvips.tex xytextures.tex xy16textures.tex xyoztex.tex xy17oztex.tex \
	xycmactex.tex xydvitops.tex xyemtex.tex xydvidrv.tex xyxdvi.tex \
	xymovie.tex xyv2.tex xypic.tex \
	xynecula.tex xysmart.tex

MACRORUN =		$(KERNELRUN) $(OPTIONRUN) $(FORMATSOURCES) \
			$(LATEXSTYLES)
PSRUN = 		xy$(SHORTVERSION)dict.pro

SUPPORT =		install-tds doc2tex.com \
			dvitogif89a pnmrawtopcropwhite.c 

# Macros have .tex suffix and are generated from the .doc files.
#
.SUFFIXES:	.tex .doc
.doc.tex:;	$(DOC2TEX) $< > $@
#
.PHONY:		macros install.macros
#
macros: 	$(MACRORUN)
install.macros:	$(MACRORUN)
	-test -d $(TEXINPUTDIR) || $(MKDIR) $(TEXINPUTDIR)
	for f in $(MACRORUN); do $(INSTALL) $$f $(TEXINPUTDIR)/$$f; done
#
# Kernel dependencies:
#
xy.tex:				xy.doc
xyidioms.tex:			xyidioms.doc
xyrecat.tex:			xyrecat.doc
#
# Extension option dependencies:
#
xyframe.tex:			xyframe.doc
xytips.tex:			xytips.doc
xycmtip.tex:			xycmtip.doc
xycurve.tex:			xycurve.doc
xyline.tex:			xyline.doc
xyrotate.tex:			xyrotate.doc
xycolor.tex:			xycolor.doc
xycrayon.tex:			xycrayon.doc
xyimport.tex:			xyimport.doc
xytile.tex:			xytile.doc
#
xytpic.tex:			xytpic.doc
xytp-f.tex:			xytp-f.doc
#
xyemtex.tex:			xyemtex.doc
#
xyps.tex:			xyps.doc
xyps-ps.tex:			xyps-ps.doc
xyps-pro.tex:			xyps-pro.doc
xyps-col.tex:			xyps-col.doc
xyps-c.tex:			xyps-c.doc
xyps-f.tex:			xyps-f.doc
xyps-l.tex:			xyps-l.doc
xyps-r.tex:			xyps-r.doc
xyps-s.tex:			xyps-s.doc
xyps-t.tex:			xyps-t.doc
xypsdict.tex:			xypsdict.doc
xypspatt.tex:			xypspatt.doc
#
# Feature option dependencies:
#
xydummy.tex:			xydummy.doc
xyall.tex:			xyall.doc
#
xymatrix.tex:			xymatrix.doc
xyarrow.tex:			xyarrow.doc
xygraph.tex:			xygraph.doc
xy2cell.tex:			xy2cell.doc
xypoly.tex:			xypoly.doc
xyarc.tex:			xyarc.doc
xyknot.tex:			xyknot.doc
xyweb.tex:			xyweb.doc
#
# Driver option dependencies:
#
xycmactex.tex:			xycmactex.doc
xydvips.tex:			xydvips.doc
xydvitops.tex:			xydvitops.doc
xydvidrv.tex:			xydvidrv.doc
xydocps.tex:			xydocps.doc
xytextures.tex:			xytextures.doc
xy16textures.tex:		xy16textures.doc
xyoztex.tex:			xyoztex.doc
xymovie.tex:			xymovie.doc
xy17oztex.tex:			xy17oztex.doc
xyxdvi.tex:			xyxdvi.doc
#
# Backwards compatibility dependencies:
#
xyv2.tex:			xyv2.doc
xypic.tex:			xypic.doc
#
# Required documentation files
#
install.trailer:	$(TRAILERRUN)
	-test -d $(TEXDOCDIR) || $(MKDIR) $(TEXDOCDIR)
	for f in $(TRAILERRUN); do $(INSTALL) $$f $(TEXDOCDIR)/$$f; done


# PostScript HEADERS:
#
.PHONY: install.ps
install.ps:		$(PSRUN)
	test -d $(PSHEADERDIR) || $(MKDIR) $(PSHEADERDIR)
	for f in $(PSRUN); do $(INSTALL) $$f $(PSHEADERDIR)/$$f; done


# FONTS.
#
.PHONY:		mfinputs texfonts $(PK)fonts fonts install.fonts \
		psfonts install.psfonts obsoletefonts install.obsoletefonts
#
METAFONTS = \
	xydash10.mf xybsql10.mf xyd2.mf \
	xyatip10.mf xybtip10.mf xytech.mf xyatip.mf xybtip.mf xyd.mf \
	xycirc10.mf \
	xycmat10.mf xycmbt10.mf xycmat11.mf xycmbt11.mf \
	 xycmat12.mf xycmbt12.mf xycm.mf \
	xyeuat10.mf xyeubt10.mf xyeuat11.mf xyeubt11.mf \
	 xyeuat12.mf xyeubt12.mf xyeuler.mf
#
TEXFONTRUN = \
	xydash10.tfm xybsql10.tfm xyatip10.tfm xybtip10.tfm xycirc10.tfm \
	xycmat10.tfm xycmbt10.tfm xycmat11.tfm xycmbt11.tfm \
	 xycmat12.tfm xycmbt12.tfm \
	xyeuat10.tfm xyeubt10.tfm xyeuat11.tfm xyeubt11.tfm \
	 xyeuat12.tfm xyeubt12.tfm
#
# Note: we only depend on the tfm-files, so you must remove them to
# regenerate the fonts at all desired magnifications.
#
.SUFFIXES:	.mf .tfm
.mf.tfm:;	$(MF2TFM)
#
mfinputs:	$(METAFONTS)
#
texfonts $(PK)fonts fonts: $(METAFONTS) $(TEXFONTRUN)
install.fonts:	fonts
	if test -n "$(MFINPUTDIR)"; then \
	  test -d $(MFINPUTDIR) || $(MKDIR) $(MFINPUTDIR); \
	  for f in $(METAFONTS);do $(INSTALL) $$f $(MFINPUTDIR)/$$f;done; fi
	-test -d $(TEXFONTDIR) || $(MKDIR) $(TEXFONTDIR)
	for f in $(TEXFONTRUN); do $(INSTALL) $$f $(TEXFONTDIR)/$$f; done
	#
	[ "$(MAGS)" = "." ] || \
	 for mode in $(MODES); do for mag in $(MAGS); do \
	  $(RM) xytest.*gf xytest.*tfm;\
	  $(MF) "\\mode=$$mode; mag=magstep($$mag); input xytest";\
	  dpi="`expr xytest.*gf : 'xytest\.\([0-9]*\)gf'`";\
	  for f in $(TEXFONTRUN); do \
	    f="`expr $$f : '\([a-z0-9]*\)\.tfm'`.$${dpi}$(PK)" ;\
	    if [ ! -f $$f ]; then echo "ERROR: FONT $$f NOT GENERATED";\
	    else test -d "$(FONTDIR)" || $(MKDIR) $(FONTDIR);\
	      $(INSTALL) $$f $(FONTDIR)/$$f; fi; done; done; done
#
xydash10.tfm:	xydash10.mf xyd2.mf xytest.mf
xybsql10.tfm:	xybsql10.mf xyd.mf xytest.mf
xycirc10.tfm:	xycirc10.mf xytest.mf
xyatip10.tfm:	xyatip10.mf xytech.mf xyatip.mf xyd.mf xytest.mf
xybtip10.tfm:	xybtip10.mf xytech.mf xybtip.mf xyd.mf xytest.mf
xycmat10.tfm:	xycmat10.mf xyatip.mf xyd.mf xytest.mf
xycmbt10.tfm:	xycmbt10.mf xybtip.mf xyd.mf xytest.mf
xyeuat10.tfm:	xyeuat10.mf xyatip.mf xyd.mf xytest.mf
xyeubt10.tfm:	xyeubt10.mf xybtip.mf xyd.mf xytest.mf
#
# Obsolete fonts (from 2.6 and before).
#
OBSOLETEMETAFONTS = xyline10.mf xyqc10.mf xymisc10.mf
OBSOLETETEXFONTRUN = xyline10.tfm xyqc10.tfm xymisc10.tfm
#
obsoletefonts:	$(OBSOLETEMETAFONTS) $(OBSOLETETEXFONTRUN)
#
install.obsoletefonts:	obsoletefonts
	if test -n "$(MFINPUTDIR)"; then \
	  test -d $(MFINPUTDIR) || $(MKDIR) $(MFINPUTDIR); \
	  for f in $(OBSOLETEMETAFONTS);do $(INSTALL) $$f $(MFINPUTDIR)/$$f;done; fi
	-test -d $(TEXFONTDIR) || $(MKDIR) $(TEXFONTDIR)
	for f in $(OBSOLETETEXFONTRUN); do \
	  $(INSTALL) $$f $(TEXFONTDIR)/$$f; done
	#
	[ "$(MAGS)" = "." ] || \
	 for mode in $(MODES); do for mag in $(MAGS); do \
	  $(RM) xytest.*gf xytest.*tfm;\
	  $(MF) "\\mode=$$mode; mag=magstep($$mag); input xytest";\
	  dpi="`expr xytest.*gf : 'xytest\.\([0-9]*\)gf'`";\
	  for f in $(OBSOLETETEXFONTRUN); do \
	    f="`expr $$f : '\([a-z0-9]*\)\.tfm'`.$${dpi}$(PK)" ;\
	    if [ ! -f $$f ]; then echo "ERROR: FONT $$f NOT GENERATED";\
	    else test -d "$(FONTDIR)" || $(MKDIR) $(FONTDIR);\
	      $(INSTALL) $$f $(FONTDIR)/$$f; fi; done; done; done
#
xyline10.tfm:   xyline10.mf xytest.mf
xyqc10.tfm:     xyqc10.mf xytest.mf
xymisc10.tfm:   xymisc10.mf xytest.mf

# PostScript fonts w/support files...from Y&Y.
#
TYPE1FONTS = \
	xyatip10.pfb xybsql10.pfb xybtip10.pfb xycirc10.pfb xydash10.pfb \
	xycmat10.pfb xycmbt10.pfb xyeuat10.pfb xyeubt10.pfb
#
PFMFONTS = \
	xyatip10.pfm xybsql10.pfm xybtip10.pfm xycirc10.pfm xydash10.pfm \
	xycmat10.pfm xycmbt10.pfm xyeuat10.pfm xyeubt10.pfm
#
AFMFONTS = \
	xyatip10.afm xybsql10.afm xybtip10.afm xycirc10.afm xydash10.afm \
	xycmat10.afm xycmbt10.afm xyeuat10.afm xyeubt10.afm
#
YANDYFONTS = $(TYPE1FONTS) $(AFMFONTS) $(PFMFONTS)
#
psfonts: $(YANDYFONTS)
#
$(YANDYFONTS): YandY_xy_fonts.zip
	unzip -aoL YandY_xy_fonts.zip
	touch $(YANDYFONTS)
#
install.psfonts: psfonts xypic.map
	test -d $(TYPE1DIR) || $(MKDIR) $(TYPE1DIR)
	test -d $(PFMDIR) || $(MKDIR) $(PFMDIR)
	test -d $(AFMDIR) || $(MKDIR) $(AFMDIR)
	test -d $(PDFDIR) || $(MKDIR) $(PDFDIR)
	for f in $(TYPE1FONTS); do $(INSTALL) $$f $(TYPE1DIR)/$$f; done
	for f in $(PFMFONTS); do $(INSTALL) $$f $(PFMDIR)/$$f; done
	for f in $(AFMFONTS); do $(INSTALL) $$f $(AFMDIR)/$$f; done
	test -d $(PSHEADERDIR) || $(MKDIR) $(PSHEADERDIR)
	$(INSTALL) xypic.map $(PSHEADERDIR)/xypic.map
#
# All together...
#
FONTSOURCES = $(METAFONTS) $(OBSOLETEMETAFONTS) xytest.mf \
	YandY_xy_fonts.zip xypic.map

# FORMATS:
#
# Build formats...
#
.SUFFIXES:	.ini .fmt
.ini.fmt:;	$(INITEX) $<
#
xytex.fmt:	xytex.ini macros
xylatex.fmt:	xylatex.ini macros
#xyamslatex.fmt:	xyamslatex.ini macros
#xydoc.fmt:	xydoc.ini macros


# MANUAL: USER'S GUIDE AND REFERENCE MANUAL.
#
# Note: the first generations use the DVIPS backend to run faster.
#
.PHONY:		guide manual install.manual manual.ps
#
MANUALDATA = ross.eps kris.eps import1.eps
MANUALSOURCES =		\
	xyguide.man xydoc.sty latin1.sty xydoc.bib xydoc.back \
	xyrefer.man $(KERNELSOURCES) $(LATEXSTYLES) $(OPTIONSOURCES) \
	$(OPTIONDATA) $(MANUALDATA)
#
MANUALRUN = 	xyguide.dvi xyrefer.dvi
#
.SUFFIXES:	.man .dvips .dvi .pdf
.man.dvips:
	$(MAKE) macros fonts
	echo "\\xyoption{dvips}\xyoption{ps}" > xydoc.back
	$(LATEX) $<
	@-$(CP) $<.dvi $*.dvi ; $(CP) $<.aux $*.aux ; $(CP) $<.idx $*.idx
	$(BIBTEX) $*
	@-$(CP) $*.bbl $<.bbl
	[ -f $*.idx ] && $(MAKEINDEX) $* || :
	@-$(CP) $*.ind $<.ind
	echo "\\xyoption{dvips}\xyoption{ps}" > xydoc.back
	$(LATEX) $<
	@-$(CP) $<.dvi $*.dvi ; $(CP) $<.aux $*.aux ; $(CP) $<.idx $*.idx
	[ -f $*.idx ] && makeindex $* || :
	@-$(CP) $*.ind $<.ind
	echo "\\xyoption{dvips}\xyoption{ps}" > xydoc.back
	$(LATEX) $<
	@-$(CP) $<.dvi $*.dvi ; $(CP) $<.aux $*.aux ; $(CP) $<.idx $*.idx
	mv $*.dvi $*.dvips
	touch $*.dvips
#
.dvips.dvi:
	echo '' > xydoc.back
	$(LATEX) $*.man
	@-$(CP) $*.man.dvi $*.dvi ; $(CP) $*.man.aux $*.aux ; $(CP) $*.man.idx $*.idx
	touch $*.dvi
#
.dvips.pdf:
	echo '' > xydoc.back
	$(PDFLATEX) $*.man
	@-$(CP) $*.man.pdf $*.pdf ; $(CP) $*.man.aux $*.aux ; $(CP) $*.man.idx $*.idx
	touch $*.pdf
#
guide:		xyguide.dvi 
#
manual:		$(MANUALRUN)
install.manual:	manual
	-test -d $(TEXDOCDIR) || $(MKDIR) $(TEXDOCDIR)
	for f in $(MANUALRUN); do $(INSTALL) $$f $(TEXDOCDIR)/$$f; done
#
xyguide.dvips:	xyguide.man xydoc.sty latin1.sty xydoc.bib version.tex
xyrefer.dvips:	xyrefer.man xydoc.sty latin1.sty xydoc.bib version.tex \
	$(KERNELSOURCES) $(OPTIONSOURCES) $(MANUALDATA)
xytest.dvips:	xytest.man xydoc.sty latin1.sty xydoc.bib version.tex \
	$(KERNELSOURCES) $(OPTIONSOURCES) $(MANUALDATA)
#
xyguide.dvi:	xyguide.dvips version.tex
xyrefer.dvi:	xyrefer.dvips version.tex
xytest.dvi:	xytest.dvips version.tex
#
xyguide.pdf:	xyguide.dvips version.tex
xyrefer.pdf:	xyrefer.dvips version.tex
xytest.pdf:	xytest.dvips version.tex
#
version.tex:	version.doc
	$(LATEX) version.doc
#
.SUFFIXES:	.pro
xy$(SHORTVERSION)dict.pro: xydocps.tex xypsdict.tex xypspatt.tex xyps-pro.tex
	-$(RM) xy$(SHORTVERSION)dict.pro
	$(TEX) xydocps.tex
#
# PostScript targets:
#
# DVIPS should be Tom Rokicki's dvips PostScript DVI driver as a filter.
DVIPS = dvips -D600 -f
#
.SUFFIXES:	.ps
.dvips.ps:;	$(DVIPS) < $< > $@
#
xyguide.ps:	xyguide.dvips $(PSRUN)
xyrefer.ps:	xyrefer.dvips $(PSRUN)
#
manual.ps:	xyguide.ps xyrefer.ps


# TeXNICAL DOCUMENTATION.
#
.PHONY:		TeXnical
TeXnical:	xysource.ps xysource.dvi xysource.pdf
#
TeXNICALSOURCES = xysource.man COPYING.patch xydoc.back
#
TeXNICALAUX = \
	TRAILER CATALOG README $(INSTALLSTAR) MAKE MANIFEST \
	COPYING.tex
#
xysource.dvips: xysource.man macros.tmp \
		macros fonts obsoletefonts $(ALLSOURCES) $(TeXNICALAUX)
xysource.ps:	xysource.dvips
xysource.dvi:	xysource.dvips
xysource.pdf:	xysource.dvips
#
xywork.dvips: xywork.man macros.tmp \
		macros fonts obsoletefonts $(ALLSOURCES) $(TeXNICALAUX)
xywork.ps:	xywork.dvips
xywork.dvi:	xywork.dvips
xywork.pdf:	xywork.dvips
#
COPYING.tex: COPYING COPYING.patch
	patch COPYING -o COPYING.tex < COPYING.patch
#
FONTCOPYING.tex: FONTCOPYING FONTCOPYING.patch
	patch FONTCOPYING -o FONTCOPYING.tex < FONTCOPYING.patch
#
# Macro index...requires GNU AWK (gawk) or (in a pinch) NAWK.
#
GAWK = gawk
#
macros.tmp: $(KERNELSOURCES) $(LATEXSTYLES) $(OPTIONSOURCES) $(METAFONTS)
	-$(RM) macros.tmp
	for f in $(KERNELSOURCES) $(LATEXSTYLES) $(OPTIONSOURCES) $(METAFONTS);\
	do $(GAWK) '\
	  func err(s) { printf("%s,%d: %s\n",FILENAME,FNR,s) >>"/dev/stderr"};\
	  func prt(s,i) { \
	   printf("\\filelinedef{%s}{%d}\\index def{%s}\n",FILENAME,FNR,s) };\
	  func prtdef(i) { t = substr($$0,i);\
	   if (match(t,/[\\|][a-zA-Z@]*|\\.|[^\\|]|{([^{}]|\\{|\\})*}/) != 1) \
	    err("Weird TeX token");\
	   else prt(substr($$0,i,RLENGTH),i) };\
	  func prtcsdef(i) { t = substr($$0,i);\
	   if (match(t,/{([^{}]|\\{|\\})*}|{([^{}]|\\{|\\})*{([^{}]|\\{|\\})*}([^{}]|\\{|\\})*}/) != 1) \
	    err("Weird TeX cs name token");\
	   else prt(substr($$0,i+1,RLENGTH-2),i) };\
	  /^\\let[^A-Za-z@]/		||\
	  /^\\def[^A-Za-z@]/		{ prtdef(5); next };\
	  /^\\gdef[^A-Za-z@]/		||\
	  /^\\edef[^A-Za-z@]/		||\
	  /^\\xdef[^A-Za-z@]/		{ prtdef(6); next };\
	  /^\\newif[^A-Za-z@]/		{ prtdef(7); next };\
	  /^\\xydef@[^A-Za-z@]/		||\
	  /^\\xylet@[^A-Za-z@]/		{ prtdef(8); next };\
	  /^\\xyfont@[^A-Za-z@]/	{ prtdef(9); next };\
	  /^\\global\\let[^A-Za-z@]/	{ prtdef(12); next };\
	  /^\\xywarnifdefined[^A-Za-z@]/ { prtdef(17); next };\
	  /^\\ifx\\undefined[^A-Za-z@]/ { prtdef(15); next };\
	  /^\\xynew@{[^{}]*}/		{ prtdef(index($$0,"}")+1); next };\
	  /^\\xydefcsname@{/		{ prtcsdef(14); next };\
	  /^\\xyletcsnamecsname@{/	{ prtcsdef(20); next }' $$f;\
	done | sed -e 's,\\{,\\\\otherebgroup,' -e 's,\\},\\\\otheregroup,' \
	> macros.tmp

###printf("\\macroentry{%s}{%s}{%d}\n",s,FILENAME,FNR) };\


# Xy-pic the MOVIE :)
#
.SUFFIXES: .texmovie .gif
#
.texmovie.gif:
	$(LATEX) '\documentclass[dvips]{movie}' \
		'\usepackage[all]{xy}' \
		'\begin{document}' \
		'\input{$*.texmovie}' \
		'\end{document}'
	@-[ -f texput.dvi ] && $(MV) texput.dvi $*.dvi && $(MV) texput.size $*.size
	@-[ -f movie.cls.dvi ] && $(MV) movie.cls.dvi $*.dvi && $(MV) movie.cls.size $*.size
	@-[ -f movie.dvi ] && $(MV) movie.dvi $*.dvi && $(MV) movie.size $*.size
	./dvitogif89a $*.dvi
#
.texmovie.dvi:
	$(LATEX) '\documentclass{article}' \
		'\usepackage[movie,all]{xy}' \
		'\begin{document}' \
		'\title{Storyboard for ``$*.''}' \
		'\maketitle' \
		'\input{$*.texmovie}' \
		'\end{document}'
#
dragon.gif:	dragon.texmovie movie.cls dvitogif89a
dragon.dvi:	dragon.texmovie movie.cls
#
sesam.gif:	sesam.texmovie movie.cls dvitogif89a
sesam.dvi:	sesam.texmovie movie.cls
#
gasket.dvi:	gasket.texmovie movie.cls dvitogif89a
gasket.gif:	gasket.texmovie movie.cls


# DISTRIBUTION TREE.
#
DISTDIR = $(FTPROOT)/xy-$(VERSION)
DISTFONTDIR = $(DISTDIR)/$(PK)fonts/$${mode}$${dpi}
#
# Files:
#
SOURCES = $(MACROSOURCES) $(FONTSOURCES) $(MANUALSOURCES) $(SUPPORT)
#
# Commands:
#
# TAR <files>		output tar archive with <files>
# GZIP			compression filter
# GZ			filename extension appropriate for compressed files
#
# TODO: change compression to proper GNU gzip once everyone supports it...
#
TAR = tar cvf -
GZIP = gzip -v9
GZ = .gz
#
# Targets:
#
.PHONY: dist dist-$(VERSION) distsrc distrun distdoc
#
dist dist-$(VERSION):
	cd $(DISTDIR);\
	  find . -type f -print | sed 's,^./,,' | sort > MANIFEST
	$(INSTALL) README $(DISTDIR)/README
#
distsrc:	$(DISTDIR)/src
#
distrun:	$(DISTDIR)/CATALOG \
		$(DISTDIR)/TRAILER \
		$(DISTDIR)/README \
		$(DISTDIR)/INSTALL \
		$(DISTDIR)/VERSIONS \
		$(DISTDIR)/texinputs \
		$(DISTDIR)/texfonts \
		$(DISTDIR)/mfinputs \
		$(DISTDIR)/$(PK)fonts \
		$(DISTDIR)/doc/xyguide.dvi \
		$(DISTDIR)/doc/xyrefer.dvi \
		$(DISTDIR)/doc/xysource.dvi \
		$(DISTDIR)/ps \
		$(DISTDIR)/type1 \
		$(DISTDIR)/pfm \
		$(DISTDIR)/afm \
		$(DISTDIR)/COPYING \
		$(DISTDIR)/support
#
distdoc:	$(DISTDIR)/doc/xyguide.dvips \
		$(DISTDIR)/doc/xyguide.ps \
		$(DISTDIR)/doc/xyguide.pdf \
		$(DISTDIR)/doc/xyrefer.dvips \
		$(DISTDIR)/doc/xyrefer.ps \
		$(DISTDIR)/doc/xyrefer.pdf \
		$(DISTDIR)/doc/xysource.dvips \
		$(DISTDIR)/doc/xysource.ps
#### CURRENTLY BROKEN:
#		$(DISTDIR)/doc/xyguide-html \
#
# Explanation targets:
#
# CATALOG is automatically generated:
#
$(DISTDIR)/CATALOG: CATALOG $(DISTDIR)
	$(INSTALL) CATALOG $(DISTDIR)/CATALOG
#
CATALOG:	CATALOG.doc
	$(LATEX) CATALOG.doc
	mv -f CATALOG.out CATALOG

$(DISTDIR)/TRAILER: TRAILER $(DISTDIR)
	$(INSTALL) TRAILER $(DISTDIR)/TRAILER

$(DISTDIR)/README: README $(DISTDIR)
	$(INSTALL) README $(DISTDIR)/README
 
$(DISTDIR)/VERSIONS: VERSIONS $(DISTDIR)
	$(INSTALL) VERSIONS $(DISTDIR)/VERSIONS

$(DISTDIR)/INSTALL: $(INSTALLSTAR) $(DISTDIR)
	for f in $(INSTALLSTAR); do if test -f "$$f"; then \
	  $(INSTALL) $$f $(DISTDIR)/$$f; else :; fi; done

$(DISTDIR)/COPYING: COPYING $(DISTDIR)
	$(INSTALL) COPYING $(DISTDIR)/COPYING

$(DISTDIR)/FONTCOPYING: FONTCOPYING $(DISTDIR)
	$(INSTALL) FONTCOPYING $(DISTDIR)/FONTCOPYING
#
# Directory targets:
#
$(DISTDIR):
	-test -d $(DISTDIR) || $(MKDIR) $(DISTDIR)

$(DISTDIR)/src: $(SOURCES) MANIFEST VERSIONS ChangeLog $(DISTDIR)
	-test -d $(DISTDIR)/src || $(MKDIR) $(DISTDIR)/src
	for f in $(SOURCES); do echo $$f; done | sort -fu |\
	 while read u; do $(INSTALL) $$u $(DISTDIR)/src/$$u; done
	echo '' > xydoc.back
	$(INSTALLW) xydoc.back $(DISTDIR)/src
	$(INSTALLW) MANIFEST VERSIONS ChangeLog $(DISTDIR)/src

xydoc.back:
	echo '' > xydoc.back
#
# The MANIFEST in src is just a list of the distributed source files.
#
MANIFEST:	$(SOURCES)
	ls -alg `for f in $(SOURCES); do echo $$f; done | sort -fu` >MANIFEST
#
# The VERSIONS is just a list of the RCS versions.
#
VERSIONS:	$(SOURCES)
	sed -n 's/^.*\([$$]Id[:][^$$]*[$$]\).*$$/\1/p' \
	 `for f in $(SOURCES); do echo $$f; done | sort -u` >VERSIONS

$(DISTDIR)/texinputs: macros $(DISTDIR)
	-test -d $(DISTDIR)/texinputs \
	 || $(MKDIR) $(DISTDIR)/texinputs
	for f in $(MACRORUN) $(LATEXSTYLES); \
	 do $(INSTALL) $$f $(DISTDIR)/texinputs/$$f; done

$(DISTDIR)/texfonts: texfonts obsoletefonts $(DISTDIR)
	-test -d $(DISTDIR)/texfonts \
	 || $(MKDIR) $(DISTDIR)/texfonts
	for f in $(TEXFONTRUN) $(OBSOLETETEXFONTRUN); \
	 do $(INSTALL) $$f $(DISTDIR)/texfonts/$$f; done

$(DISTDIR)/mfinputs: mfinputs $(OBSOLETEMETAFONTS) $(DISTDIR)
	-test -d $(DISTDIR)/mfinputs || $(MKDIR) $(DISTDIR)/mfinputs
	for f in $(METAFONTS) $(OBSOLETEMETAFONTS); \
	 do $(INSTALL) $$f $(DISTDIR)/mfinputs/$$f; done

$(DISTDIR)/$(PK)fonts: $(PK)fonts $(DISTDIR)
	-test -d $(DISTDIR)/$(PK)fonts || $(MKDIR) $(DISTDIR)/$(PK)fonts
	:
	for mode in $(MODES); do for mag in $(MAGS); do \
	  $(RM) xytest.*gf xytest.*tfm;\
	  $(MF) "\\mode=$$mode; mag=magstep($$mag); input xytest";\
	  dpi="`expr xytest.*gf : 'xytest\.\([0-9]*\)gf'`";\
	  for f in $(TEXFONTRUN); do \
	    f="`expr $$f : '\([a-z0-9]*\)\.tfm'`.$${dpi}$(PK)" ;\
	    if [ ! -f $$f ]; then echo "ERROR: FONT $$f NOT GENERATED";\
	    else test -d "$(DISTFONTDIR)" || $(MKDIR) $(DISTFONTDIR);\
	      $(INSTALL) $$f $(DISTFONTDIR)/$$f; fi; done; done; done

$(DISTDIR)/ps: xy$(SHORTVERSION)dict.pro xypic.map $(DISTDIR)
	-test -d $(DISTDIR)/ps || $(MKDIR) $(DISTDIR)/ps
	$(INSTALL) xy$(SHORTVERSION)*dict.pro $(DISTDIR)/ps
	$(INSTALL) xypic.map $(DISTDIR)/ps

$(DISTDIR)/type1: $(TYPE1FONTS) $(DISTDIR)
	-test -d $(DISTDIR)/type1 || $(MKDIR) $(DISTDIR)/type1
	for f in $(TYPE1FONTS) ; \
	 do $(INSTALL) $$f $(DISTDIR)/type1/$$f; done

$(DISTDIR)/pfm: $(PFMFONTS) $(DISTDIR)
	-test -d $(DISTDIR)/pfm || $(MKDIR) $(DISTDIR)/pfm
	for f in $(PFMFONTS) ; \
	 do $(INSTALL) $$f $(DISTDIR)/pfm/$$f; done

$(DISTDIR)/afm: $(AFMFONTS) $(DISTDIR)
	-test -d $(DISTDIR)/afm || $(MKDIR) $(DISTDIR)/afm
	for f in $(AFMFONTS) ; \
	 do $(INSTALL) $$f $(DISTDIR)/afm/$$f; done

$(DISTDIR)/pdftex: $(DISTDIR) xypic.map
	-test -d $(DISTDIR)/pdftex || $(MKDIR) $(DISTDIR)/pdftex
	$(INSTALL) xypic.map $(DISTDIR)/pdftex

$(DISTDIR)/support: $(SUPPORT)
	-test -d $(DISTDIR)/support || $(MKDIR) $(DISTDIR)/support
	for f in $(SUPPORT) ; \
	 do $(INSTALLX) $$f $(DISTDIR)/support/$$f; done

# Document targets:
#
$(DISTDIR)/doc/xyguide.dvi:	xyguide.dvi $(DISTDIR)/doc
	$(INSTALL) xyguide.dvi $(DISTDIR)/doc

$(DISTDIR)/doc/xyguide.dvips:	xyguide.dvips $(DISTDIR)/doc
	$(INSTALL) xyguide.dvips $(DISTDIR)/doc

$(DISTDIR)/doc/xyguide.pdf:	xyguide.pdf $(DISTDIR)/doc
	$(INSTALL) xyguide.pdf $(DISTDIR)/doc

$(DISTDIR)/doc/xyguide.ps:	xyguide.ps $(DISTDIR)/doc
	$(INSTALL) xyguide.ps $(DISTDIR)/doc

$(DISTDIR)/doc/xyguide-html:	xyguide-html $(DISTDIR)/doc
	tar cf - xyguide-html | (cd $(DISTDIR)/doc; tar xpvf -)

$(DISTDIR)/doc/xyrefer.dvi:	xyrefer.dvi $(DISTDIR)/doc
	$(INSTALL) xyrefer.dvi $(DISTDIR)/doc

$(DISTDIR)/doc/xyrefer.dvips:	xyrefer.dvips ross.eps kris.eps import1.eps \
				$(DISTDIR)/doc
	$(INSTALL) xyrefer.dvips ross.eps kris.eps import1.eps $(DISTDIR)/doc

$(DISTDIR)/doc/xyrefer.pdf:	xyrefer.pdf ross.eps kris.eps import1.eps \
				$(DISTDIR)/doc
	$(INSTALL) xyrefer.pdf $(DISTDIR)/doc

$(DISTDIR)/doc/xyrefer.ps:	xyrefer.ps $(DISTDIR)/doc
	$(INSTALL) xyrefer.ps $(DISTDIR)/doc

$(DISTDIR)/doc/xyrefer-html:	xyrefer-html $(DISTDIR)/doc
	$(INSTALL) xyrefer-html $(DISTDIR)/doc

$(DISTDIR)/doc/xysource.dvi:	xysource.dvi $(DISTDIR)/doc
	$(INSTALL) xysource.dvi $(DISTDIR)/doc

$(DISTDIR)/doc/xysource.dvips:	xysource.dvips ross.eps kris.eps import1.eps \
				$(DISTDIR)/doc
	$(INSTALL) xysource.dvips ross.eps kris.eps import1.eps $(DISTDIR)/doc

$(DISTDIR)/doc/xysource.ps:	xysource.ps $(DISTDIR)/doc
	$(INSTALL) xysource.ps $(DISTDIR)/doc

$(DISTDIR)/doc:
	-test -d $(DISTDIR)/doc || $(MKDIR) $(DISTDIR)/doc


# FTP'ABLE DISTRIBUTION.
#
FTPROOT = $$HOME/public_ftp/TeX
FTPDOCDIR = $(FTPROOT)/xy-$(VERSION)/doc
#
.PHONY:		ftp ftp-$(VERSION) ftpsrc ftprun ftpdoc ftpunpacked
#
ftp ftp-$(VERSION):	ftpsrc ftprun ftpdoc ftpunpacked
	$(INSTALL) TRAILER $(FTPROOT)/xy$(SHORTVERSION).TRAILER
#
ftpsrc $(FTPROOT)/xy$(SHORTVERSION)src.tar$(GZ): distsrc
	cd $(DISTDIR)/.. ;\
	 $(TAR) xy-$(VERSION)/src \
	 | $(GZIP) > $(FTPROOT)/xy$(SHORTVERSION)src.tar$(GZ)
#
ftpdoc $(FTPROOT)/xy$(SHORTVERSION)doc.tar$(GZ): distrun distdoc
	cd $(DISTDIR)/.. ;\
	 $(TAR) xy-$(VERSION)/doc \
	 | $(GZIP) > $(FTPROOT)/xy$(SHORTVERSION)doc.tar$(GZ)
	$(GZIP) < xyguide.dvi > $(FTPROOT)/xyguide.dvi$(GZ)
	$(GZIP) < xyguide.dvips > $(FTPROOT)/xyguide.dvips$(GZ)
	$(GZIP) < xyguide.ps    > $(FTPROOT)/xyguide.ps$(GZ)
	$(GZIP) < xyguide.pdf    > $(FTPROOT)/xyguide.pdf$(GZ)
	$(GZIP) < xyrefer.dvi > $(FTPROOT)/xyrefer.dvi$(GZ)
	$(GZIP) < xyrefer.dvips > $(FTPROOT)/xyrefer.dvips$(GZ)
	$(GZIP) < xyrefer.ps    > $(FTPROOT)/xyrefer.ps$(GZ)
	$(GZIP) < xyrefer.pdf    > $(FTPROOT)/xyrefer.pdf$(GZ)
	$(GZIP) < xysource.dvi > $(FTPROOT)/xysource.dvi$(GZ)
	$(GZIP) < xysource.dvips > $(FTPROOT)/xysource.dvips$(GZ)
	$(GZIP) < xysource.ps    > $(FTPROOT)/xysource.ps$(GZ)
#	$(TAR) xyguide-html | $(GZIP) > $(FTPROOT)/xyguide-html.tar.gz
#
ftprun $(FTPROOT)/xy$(SHORTVERSION)run.tar$(GZ): distrun
	cd $(DISTDIR)/.. ;\
	 $(TAR) \
	  `for f in $(TRAILERRUN); do echo xy-$(VERSION)/$$f; done` \
	  xy-$(VERSION)/texinputs xy-$(VERSION)/mfinputs \
	  xy-$(VERSION)/texfonts xy-$(VERSION)/$(PK)fonts \
	  xy-$(VERSION)/ps xy-$(VERSION)/type1 xy-$(VERSION)/pfm \
	  xy-$(VERSION)/afm \
	  xy-$(VERSION)/support \
	 | $(GZIP) > $(FTPROOT)/xy$(SHORTVERSION)run.tar$(GZ)
#
ftpunpacked: dist
	test $(DISTDIR) = $(FTPROOT)/xy-$(VERSION) || \
	 (cd $(DISTDIR)/.. ; tar cf - xy-$(VERSION) |(cd $(FTPROOT); tar xvf -))
	cd $(FTPROOT); rm -f xy; ln -fs xy-$(VERSION) xy


# WWW/HTML DOCUMENTATION & HYPE.
#
WWWDIR = $$HOME/public_html
#
WWWSOURCES =	Xy-pic.html Xy.doc Xy.xy \
		man2html.gawk man2html-post.gawk .latex2html-init
#
.PHONY: 	guide.html www install.www
#
LATEX2HTML = 	latex2html
#
LATEX2HTMLICONDIR = $$HOME/src/latex2html-96.1/icons
LATEX2HTMLICONDIR2 = $$HOME/CV
#
man2html =	$(GAWK) -f man2html.gawk
man2htmlpost =	$(GAWK) -f ../man2html-post.gawk
#
guide.html:	xyguide-html
#
xyguide-html.tex: xyguide.dvips xyguide.man $(WWWSOURCES)
	$(man2html) <xyguide.aux >xyguide-html.aux
	$(man2html) <xyguide.bbl >xyguide-html.bbl
	@-$(CP) xyguide.man.ans xyguide.ans
	@-$(CP) xyguide.man.idx xyguide.idx
	@-$(CP) xyguide.man.ind xyguide.ind
	$(man2html) <xyguide.ans >xyguide-html.ans
	$(man2html) <xyguide.idx >xyguide-html.idx
	$(man2html) <xyguide.ind | sed 's/"/|/g' >xyguide-html.ind
	$(man2html) <xyguide.man >xyguide-html.tex
#
xyguide-html-act:	xyguide-html.tex version.tex
	echo "\\xyoption{dvips}\xyoption{ps}" > xydoc.back
	$(LATEX2HTML) xyguide-html.tex
#
xyguide-html:	xyguide-html.tex xyguide-html-act
	(cd xyguide-html; \
	 for f in *.html; do mv $$f $$f~; \
	  $(man2htmlpost) <$$f~ \
	  | sed -e 's/``/"/g' -e "s/''/\"/g" -e 's/  [>] />/g' >$$f; done; \
	 (cd $$HOME/W3; tar cf - COPYING) | tar xpf - )
	:
	cp "$(LATEX2HTMLICONDIR2)/18pt.html" xyguide-html
	cat xyguide-html/*.html \
	| tr '"' "\n" \
	| sed -n 's;[.][/]\([a-z_]*[.]gif\);\1;p' | sort -u \
	| while read f ;\
	  do if [ -f "$(LATEX2HTMLICONDIR2)/$$f" ]; \
	     then echo "[$$f]"; cp $(LATEX2HTMLICONDIR2)/$$f xyguide-html ; \
	     elif [ -f "$(LATEX2HTMLICONDIR)/$$f" ]; \
	     then echo "[$$f]"; cp $(LATEX2HTMLICONDIR)/$$f xyguide-html ; \
	     fi ; done
	:
	(cd xyguide-html; \
	 $(RM) .I* .O* *.ppm *.xyc *.ans *.aux *.idx *.bbl *.log *.tex *~)
#
Xy.tex:	Xy.doc
Xy.dvi:	Xy.tex Xy.xy macros; $(LATEX) Xy
Xy.ps:	Xy.dvi; $(DVIPS) Xy.dvi -oXy.ps
#
PNMCROP = ./pnmrawtopcropwhite | pnmcrop
PGMTOGIF = pgmtoppm rgbi:1/1/1 | ppmtogif -interlace -transparent rgbi:1/1/1
#
Xy.gif:	Xy.ps pnmrawtopcropwhite
	echo '' | \
	 gs -sDEVICE=pbmraw -r300 \
	  -sOutputFile='|$(PNMCROP) >Xy.pbm' \
	  -q - Xy.ps
	cat Xy.pbm | $(PGMTOGIF) >Xy.gif
#
pnmrawtopcropwhite: pnmrawtopcropwhite.c
#
www:		Xy-pic.html Xy.gif
####BROKEN##### guide.html
#
install.www:	www
	$(INSTALL) Xy-pic.html Xy.gif $(WWWDIR)
#	$(RM) $(WWWDIR)/xyguide-html
#	$(MKDIR) $(WWWDIR)/xyguide-html
#	tar -cf - xyguide-html | (cd $(WWWDIR); tar xvpf -)


# ANNOUNCEMENTS.
#
MAILSOURCES = TRAILER Users mail.Users
#
.PHONY:		announce
announce:	$(MAILSOURCES)
	@./mail.Users


# TAGS for Emacs.
#
TAGS:	$(SOURCES)
	-$(RM) TAGS
	for f in `for ff in $(SOURCES); do echo $$ff; done |sort -u`;\
	do\
	 $(GAWK) '\
	  func err(s) { printf("%s,%d: %s\n",FILENAME,FNR,s) >>"/dev/stderr"};\
	  func prt(s,n) { printf("%s\177%d,%d\n",s,FNR,c+n) };\
	  func prtdef(i) { t = substr($$0,i);\
	   if (match(t,/[\\|][a-zA-Z@]*|\\.|[^\\|]|{([^{}]|\\{|\\})*}/) != 1) \
	    err("Weird TeX token");\
	   else prt(substr($$0,1,i+RLENGTH),i) };\
	  func prtcsdef(i) { t = substr($$0,i);\
	   if (match(t,/{([^{}]|\\{|\\})*}|{([^{}]|\\{|\\})*{([^{}]|\\{|\\})*}([^{}]|\\{|\\})*}/) != 1) \
	    err("Weird TeX cs name token");\
	   else prt(substr($$0,1,i+RLENGTH),i) };\
	  func fin() { c += length($$0) + 1; next };\
	  BEGIN { c = 0 };\
	  /^\\let[^A-Za-z@]/		||\
	  /^\\def[^A-Za-z@]/		{ prtdef(5); fin() };\
	  /^\\gdef[^A-Za-z@]/		||\
	  /^\\edef[^A-Za-z@]/		||\
	  /^\\xdef[^A-Za-z@]/		{ prtdef(6); fin() };\
	  /^\\newif[^A-Za-z@]/		{ prtdef(7); fin() };\
	  /^\\xydef@[^A-Za-z@]/		||\
	  /^\\xylet@[^A-Za-z@]/		{ prtdef(8); fin() };\
	  /^\\xyfont@[^A-Za-z@]/	{ prtdef(9); fin() };\
	  /^\\global\\let[^A-Za-z@]/	{ prtdef(12); fin() };\
	  /^\\xywarnifdefined[^A-Za-z@]/ { prtdef(17); fin() };\
	  /^\\ifx\\undefined[^A-Za-z@]/ { prtdef(15); fin() };\
	  /^\\xynew@{[^{}]*}/		{ prtdef(index($$0,"}")+1); fin() };\
	  /^\\xydefcsname@{/		{ prtcsdef(14); fin() };\
	  /^\\xyletcsnamecsname@{/	{ prtcsdef(20); fin() };\
	  /\?\?\=\[/	{ s = $$0; i = 0;\
	   while (first = index(s, "\?\?=[")) {\
	    s = substr(s,first+4); i += first+4;\
	    if (j = index(s, "]")) prt(substr($$0,1,i+j-1),i);\
	    else printf("Unmatched []s") }; fin() };\
	  /^@[A-Za-z]*{/ { prt($$0,index($$0,"{")+1); fin() };\
	  { fin() }' $$f >TAGS.tmp ;\
	 wc -c TAGS.tmp|$(GAWK) '{printf "\f\n%s,%s\n","'"$$f"'",$$1}'>>TAGS;\
	 cat TAGS.tmp >>TAGS ;\
	done
	$(RM) TAGS.tmp


# RCS STUFF:
#
.PHONY: 	ci ci-$(VERSION) cici rcscheck \
		rcslist rcslockedlist rcsunlockedlist \
		rcscleanlist rcsuncleanlist rcsclean rcsdep
#
ALLSOURCES = $(TRAILERSOURCES) $(SOURCES) $(MANUALSOURCES) $(TeXNICALSOURCES) \
	$(WWWSOURCES) $(MAILSOURCES) $(OBSOLETEMETAFONTS) $(TYPE1FONTS) \
	$(SUPPORT) xypic.map
#
ROSSSOURCES = INSTALL.OzTeX INSTALL.Textures import1.eps ross.eps \
	xy16textures.doc xy17oztex.doc xy2cell.doc xyarc.doc \
	xycolor.doc xycrayon.doc xycurve.doc \
	xydvips.doc xyimport.doc xyknot.doc xyline.doc \
	xymacpat.xyp xyoztex.doc xypoly.doc xyps-c.doc xyps-col.doc \
	xyps-f.doc xyps-l.doc xyps-pro.doc xyps-ps.doc xyps-r.doc \
	xyps-s.doc xyps-t.doc xyps.doc xypsdict.doc xypspatt.doc xyrotate.doc \
	xytextures.doc xytile.doc xytpic.doc xyemtex.doc xyweb.doc \
	xydvidrv.doc xyxdvi.doc xydvitops.doc xytp-f.doc xycmactex.doc
#
YANDYSOURCES = \
	xyatip10.pfa xybsql10.pfa xybtip10.pfa xycirc10.pfa xycmat10.pfa \
	xycmbt10.pfa xydash10.pfa xyeuat10.pfa xyeubt10.pfa \
#
ci ci-$(VERSION): $(ALLSOURCES) cici Makefile
cici:		
	-rcs -l `for f in $(ALLSOURCES); do echo $$f; done | sort -u`
	-ci -u$(VERSION) `$(MAKE) rcslockedlist`
#
rcscheck:	$(ALLSOURCES)
	@locked="`$(MAKE) rcslockedlist`"; \
	 unlocked="`$(MAKE) rcsunlockedlist`"; \
	 echo "Missing write permission on locked files:"; \
	 for f in $$locked; do [ -w "$$f" ] || echo ' '$$f; done; \
	 echo "Wrong write permission on unlocked files:"; \
	 for f in $$unlocked; do [ -w "$$f" ] && echo ' '$$f; done; \
	 echo "Wrong/missing locks on ross's files:"; \
	 for f in $(ROSSSOURCES); \
	 do lock=; \
	    for ff in $$locked; \
	    do if [ "$$f" = "$$ff" ]; then lock=' ross'; fi; done; \
	    fgrep -s " ross Exp$$lock "'$$' $$f \
	     ||(/bin/echo ' '$$f': \c' && grep 'Id[:].* Exp ' $$f || echo '?'); \
	 done; \
	 echo "Wrong/missing locks on krisrose's files:"; \
	 for f in `$(MAKE) rcslist`; \
	 do for ff in $(ROSSSOURCES); \
	    do if [ "$$f" = "$$ff" ]; then continue 2; fi; done; \
	    lock=; \
	    for ff in $$locked; \
	    do if [ "$$f" = "$$ff" ]; then lock=' krisrose'; fi; done; \
	     fgrep -s " krisrose Exp$$lock "'$$' $$f \
	     || (/bin/echo ' '$$f' \c' && grep 'Id[:].* Exp ' $$f || echo ''); \
	 done
#
rcslist:
	-@rlog -R `for f in $(ALLSOURCES); do echo $$f; done | sort -u` \
	  2>/dev/null | sed 's;RCS/\(.*\),v;\1;'
#
rcslockedlist:
	-@rlog -R -L `for f in $(ALLSOURCES); do echo $$f; done | sort -u` \
	  2>/dev/null | sed 's;RCS/\(.*\),v;\1;'
#
rcsunlockedlist:
	-@locked="`$(MAKE) rcslockedlist`"; \
	  $(MAKE) rcslist | while read f; \
	  do echo=echo; for ff in $$locked; \
	                do if [ "$$f" = "$$ff" ]; then echo=:; fi; done; \
	     $$echo $$f; done
#
rcscleanlist:
	-@$(MAKE) rcslist \
	 | while read f; do if test -w "$$f" -o "$$f" = Makefile; then :; \
	                    else echo $$f; fi; done
#
rcsuncleanlist:
	-@$(MAKE) rcslist \
	 | while read f; do if test -w "$$f" -o "$$f" = Makefile; \
	                    then echo $$f; fi; done
#
rcsclean:
	-@$(MAKE) rcscleanlist | while read f; do $(RM) $$f; done
#
# Dependencies...
#
rcsdep:
	$(MAKE) rcslist | while read f; do \
	  echo "$$f: RCS/$$f,v; test -d RCS && co $$f || :"; done

.late2html-init:; test -d RCS -a -f RCS/.late2html-init,v && co .late2html-init || :
CATALOG.doc:; test -d RCS -a -f RCS/CATALOG.doc,v && co CATALOG.doc || :
COPYING.patch:; test -d RCS -a -f RCS/COPYING.patch,v && co COPYING.patch || :
COPYING:; test -d RCS -a -f RCS/COPYING,v && co COPYING || :
FONTCOPYING.patch:; test -d RCS -a -f RCS/FONTCOPYING.patch,v && co FONTCOPYING.patch || :
FONTCOPYING:; test -d RCS -a -f RCS/FONTCOPYING,v && co FONTCOPYING || :
INSTALL.OzTeX:; test -d RCS -a -f RCS/INSTALL.OzTeX,v && co INSTALL.OzTeX || :
INSTALL.Textures:; test -d RCS -a -f RCS/INSTALL.Textures,v && co INSTALL.Textures || :
INSTALL:; test -d RCS -a -f RCS/INSTALL,v && co INSTALL || :
MAKE:; test -d RCS -a -f RCS/MAKE,v && co MAKE || :
Makefile:; test -d RCS -a -f RCS/Makefile,v && co Makefile || :
README:; test -d RCS -a -f RCS/README,v && co README || :
TRAILER:; test -d RCS -a -f RCS/TRAILER,v && co TRAILER || :
Users:; test -d RCS -a -f RCS/Users,v && co Users || :
Xy-pic.blurb:; test -d RCS -a -f RCS/Xy-pic.blurb,v && co Xy-pic.blurb || :
Xy-pic.html:; test -d RCS -a -f RCS/Xy-pic.html,v && co Xy-pic.html || :
Xy-pic.xbm:; test -d RCS -a -f RCS/Xy-pic.xbm,v && co Xy-pic.xbm || :
Xy.doc:; test -d RCS -a -f RCS/Xy.doc,v && co Xy.doc || :
Xy.xy:; test -d RCS -a -f RCS/Xy.xy,v && co Xy.xy || :
YandY_xy_fonts.zip:; test -d RCS -a -f RCS/YandY_xy_fonts.zip,v && co YandY_xy_fonts.zip || :
doc2tex.com:; test -d RCS -a -f RCS/doc2tex.com,v && co doc2tex.com || :
dvitogif89a:; test -d RCS -a -f RCS/dvitogif89a,v && co dvitogif89a || :
gasket.texmovie:; test -d RCS -a -f RCS/gasket.texmovie,v && co gasket.texmovie || :
import1.eps:; test -d RCS -a -f RCS/import1.eps,v && co import1.eps || :
install-tds:; test -d RCS -a -f RCS/install-tds,v && co install-tds || :
kris.eps:; test -d RCS -a -f RCS/kris.eps,v && co kris.eps || :
latin1.sty:; test -d RCS -a -f RCS/latin1.sty,v && co latin1.sty || :
mail.Users:; test -d RCS -a -f RCS/mail.Users,v && co mail.Users || :
man2html-post.gawk:; test -d RCS -a -f RCS/man2html-post.gawk,v && co man2html-post.gawk || :
man2html.gawk:; test -d RCS -a -f RCS/man2html.gawk,v && co man2html.gawk || :
movie.cls:; test -d RCS -a -f RCS/movie.cls,v && co movie.cls || :
pnmrawtopcropwhite.c:; test -d RCS -a -f RCS/pnmrawtopcropwhite.c,v && co pnmrawtopcropwhite.c || :
ross.eps:; test -d RCS -a -f RCS/ross.eps,v && co ross.eps || :
version.doc:; test -d RCS -a -f RCS/version.doc,v && co version.doc || :
xy.doc:; test -d RCS -a -f RCS/xy.doc,v && co xy.doc || :
xy.sty:; test -d RCS -a -f RCS/xy.sty,v && co xy.sty || :
xy16textures.doc:; test -d RCS -a -f RCS/xy16textures.doc,v && co xy16textures.doc || :
xy17oztex.doc:; test -d RCS -a -f RCS/xy17oztex.doc,v && co xy17oztex.doc || :
xy2cell.doc:; test -d RCS -a -f RCS/xy2cell.doc,v && co xy2cell.doc || :
xyall.doc:; test -d RCS -a -f RCS/xyall.doc,v && co xyall.doc || :
xyamslatex.ini:; test -d RCS -a -f RCS/xyamslatex.ini,v && co xyamslatex.ini || :
xyarc.doc:; test -d RCS -a -f RCS/xyarc.doc,v && co xyarc.doc || :
xyarrow.doc:; test -d RCS -a -f RCS/xyarrow.doc,v && co xyarrow.doc || :
xyatip10.mf:; test -d RCS -a -f RCS/xyatip10.mf,v && co xyatip10.mf || :
xybsql10.mf:; test -d RCS -a -f RCS/xybsql10.mf,v && co xybsql10.mf || :
xybtip10.mf:; test -d RCS -a -f RCS/xybtip10.mf,v && co xybtip10.mf || :
xycirc10.enc:; test -d RCS -a -f RCS/xycirc10.enc,v && co xycirc10.enc || :
xycirc10.mf:; test -d RCS -a -f RCS/xycirc10.mf,v && co xycirc10.mf || :
xycm.mf:; test -d RCS -a -f RCS/xycm.mf,v && co xycm.mf || :
xycmactex.doc:; test -d RCS -a -f RCS/xycmactex.doc,v && co xycmactex.doc || :
xycmat10.mf:; test -d RCS -a -f RCS/xycmat10.mf,v && co xycmat10.mf || :
xycmat11.mf:; test -d RCS -a -f RCS/xycmat11.mf,v && co xycmat11.mf || :
xycmat12.mf:; test -d RCS -a -f RCS/xycmat12.mf,v && co xycmat12.mf || :
xycmbt10.mf:; test -d RCS -a -f RCS/xycmbt10.mf,v && co xycmbt10.mf || :
xycmbt11.mf:; test -d RCS -a -f RCS/xycmbt11.mf,v && co xycmbt11.mf || :
xycmbt12.mf:; test -d RCS -a -f RCS/xycmbt12.mf,v && co xycmbt12.mf || :
xycmtip.doc:; test -d RCS -a -f RCS/xycmtip.doc,v && co xycmtip.doc || :
xycolor.doc:; test -d RCS -a -f RCS/xycolor.doc,v && co xycolor.doc || :
xycrayon.doc:; test -d RCS -a -f RCS/xycrayon.doc,v && co xycrayon.doc || :
xycurve.doc:; test -d RCS -a -f RCS/xycurve.doc,v && co xycurve.doc || :
xyd.enc:; test -d RCS -a -f RCS/xyd.enc,v && co xyd.enc || :
xyd.mf:; test -d RCS -a -f RCS/xyd.mf,v && co xyd.mf || :
xyd2.enc:; test -d RCS -a -f RCS/xyd2.enc,v && co xyd2.enc || :
xyd2.mf:; test -d RCS -a -f RCS/xyd2.mf,v && co xyd2.mf || :
xydash10.mf:; test -d RCS -a -f RCS/xydash10.mf,v && co xydash10.mf || :
xydoc.bib:; test -d RCS -a -f RCS/xydoc.bib,v && co xydoc.bib || :
xydoc.sty:; test -d RCS -a -f RCS/xydoc.sty,v && co xydoc.sty || :
xydocps.doc:; test -d RCS -a -f RCS/xydocps.doc,v && co xydocps.doc || :
xydriver.doc:; test -d RCS -a -f RCS/xydriver.doc,v && co xydriver.doc || :
xydummy.doc:; test -d RCS -a -f RCS/xydummy.doc,v && co xydummy.doc || :
xydvidrv.doc:; test -d RCS -a -f RCS/xydvidrv.doc,v && co xydvidrv.doc || :
xydvips.doc:; test -d RCS -a -f RCS/xydvips.doc,v && co xydvips.doc || :
xydvitops.doc:; test -d RCS -a -f RCS/xydvitops.doc,v && co xydvitops.doc || :
xyemtex.doc:; test -d RCS -a -f RCS/xyemtex.doc,v && co xyemtex.doc || :
xyeuat10.mf:; test -d RCS -a -f RCS/xyeuat10.mf,v && co xyeuat10.mf || :
xyeuat11.mf:; test -d RCS -a -f RCS/xyeuat11.mf,v && co xyeuat11.mf || :
xyeuat12.mf:; test -d RCS -a -f RCS/xyeuat12.mf,v && co xyeuat12.mf || :
xyeubt10.mf:; test -d RCS -a -f RCS/xyeubt10.mf,v && co xyeubt10.mf || :
xyeubt11.mf:; test -d RCS -a -f RCS/xyeubt11.mf,v && co xyeubt11.mf || :
xyeubt12.mf:; test -d RCS -a -f RCS/xyeubt12.mf,v && co xyeubt12.mf || :
xyeuler.doc:; test -d RCS -a -f RCS/xyeuler.doc,v && co xyeuler.doc || :
xyframe.doc:; test -d RCS -a -f RCS/xyframe.doc,v && co xyframe.doc || :
xygraph.doc:; test -d RCS -a -f RCS/xygraph.doc,v && co xygraph.doc || :
xyguide.man:; test -d RCS -a -f RCS/xyguide.man,v && co xyguide.man || :
xyidioms.doc:; test -d RCS -a -f RCS/xyidioms.doc,v && co xyidioms.doc || :
xyimport.doc:; test -d RCS -a -f RCS/xyimport.doc,v && co xyimport.doc || :
xyknot.doc:; test -d RCS -a -f RCS/xyknot.doc,v && co xyknot.doc || :
xylatex.ini:; test -d RCS -a -f RCS/xylatex.ini,v && co xylatex.ini || :
xyline.doc:; test -d RCS -a -f RCS/xyline.doc,v && co xyline.doc || :
xyline10.mf:; test -d RCS -a -f RCS/xyline10.mf,v && co xyline10.mf || :
xymacpat.xyp:; test -d RCS -a -f RCS/xymacpat.xyp,v && co xymacpat.xyp || :
xymatrix.doc:; test -d RCS -a -f RCS/xymatrix.doc,v && co xymatrix.doc || :
xymisc10.mf:; test -d RCS -a -f RCS/xymisc10.mf,v && co xymisc10.mf || :
xymovie.doc:; test -d RCS -a -f RCS/xymovie.doc,v && co xymovie.doc || :
xyoztex.doc:; test -d RCS -a -f RCS/xyoztex.doc,v && co xyoztex.doc || :
xypic.doc:; test -d RCS -a -f RCS/xypic.doc,v && co xypic.doc || :
xypic.map:; test -d RCS -a -f RCS/xypic.map,v && co xypic.map || :
xypic.sty:; test -d RCS -a -f RCS/xypic.sty,v && co xypic.sty || :
xypoly.doc:; test -d RCS -a -f RCS/xypoly.doc,v && co xypoly.doc || :
xyps-c.doc:; test -d RCS -a -f RCS/xyps-c.doc,v && co xyps-c.doc || :
xyps-col.doc:; test -d RCS -a -f RCS/xyps-col.doc,v && co xyps-col.doc || :
xyps-dto.doc:; test -d RCS -a -f RCS/xyps-dto.doc,v && co xyps-dto.doc || :
xyps-dvi.doc:; test -d RCS -a -f RCS/xyps-dvi.doc,v && co xyps-dvi.doc || :
xyps-f.doc:; test -d RCS -a -f RCS/xyps-f.doc,v && co xyps-f.doc || :
xyps-l.doc:; test -d RCS -a -f RCS/xyps-l.doc,v && co xyps-l.doc || :
xyps-one.doc:; test -d RCS -a -f RCS/xyps-one.doc,v && co xyps-one.doc || :
xyps-oz.doc:; test -d RCS -a -f RCS/xyps-oz.doc,v && co xyps-oz.doc || :
xyps-pro.doc:; test -d RCS -a -f RCS/xyps-pro.doc,v && co xyps-pro.doc || :
xyps-ps.doc:; test -d RCS -a -f RCS/xyps-ps.doc,v && co xyps-ps.doc || :
xyps-pub.doc:; test -d RCS -a -f RCS/xyps-pub.doc,v && co xyps-pub.doc || :
xyps-r.doc:; test -d RCS -a -f RCS/xyps-r.doc,v && co xyps-r.doc || :
xyps-s.doc:; test -d RCS -a -f RCS/xyps-s.doc,v && co xyps-s.doc || :
xyps-t.doc:; test -d RCS -a -f RCS/xyps-t.doc,v && co xyps-t.doc || :
xyps-txo.doc:; test -d RCS -a -f RCS/xyps-txo.doc,v && co xyps-txo.doc || :
xyps-txt.doc:; test -d RCS -a -f RCS/xyps-txt.doc,v && co xyps-txt.doc || :
xyps-wdo.doc:; test -d RCS -a -f RCS/xyps-wdo.doc,v && co xyps-wdo.doc || :
xyps.doc:; test -d RCS -a -f RCS/xyps.doc,v && co xyps.doc || :
xypsdict.doc:; test -d RCS -a -f RCS/xypsdict.doc,v && co xypsdict.doc || :
xypspatt.doc:; test -d RCS -a -f RCS/xypspatt.doc,v && co xypspatt.doc || :
xyqc10.mf:; test -d RCS -a -f RCS/xyqc10.mf,v && co xyqc10.mf || :
xyrecat.doc:; test -d RCS -a -f RCS/xyrecat.doc,v && co xyrecat.doc || :
xyrefer.man:; test -d RCS -a -f RCS/xyrefer.man,v && co xyrefer.man || :
xyrotate.doc:; test -d RCS -a -f RCS/xyrotate.doc,v && co xyrotate.doc || :
xysmart.doc:; test -d RCS -a -f RCS/xysmart.doc,v && co xysmart.doc || :
xysource.man:; test -d RCS -a -f RCS/xysource.man,v && co xysource.man || :
xystyle.doc:; test -d RCS -a -f RCS/xystyle.doc,v && co xystyle.doc || :
xytech.mf:; test -d RCS -a -f RCS/xytech.mf,v && co xytech.mf || :
xytest.mf:; test -d RCS -a -f RCS/xytest.mf,v && co xytest.mf || :
xytex.ini:; test -d RCS -a -f RCS/xytex.ini,v && co xytex.ini || :
xytextures.doc:; test -d RCS -a -f RCS/xytextures.doc,v && co xytextures.doc || :
xytile.doc:; test -d RCS -a -f RCS/xytile.doc,v && co xytile.doc || :
xytips.doc:; test -d RCS -a -f RCS/xytips.doc,v && co xytips.doc || :
xytp-f.doc:; test -d RCS -a -f RCS/xytp-f.doc,v && co xytp-f.doc || :
xytpic.doc:; test -d RCS -a -f RCS/xytpic.doc,v && co xytpic.doc || :
xyv2.doc:; test -d RCS -a -f RCS/xyv2.doc,v && co xyv2.doc || :
xyweb.doc:; test -d RCS -a -f RCS/xyweb.doc,v && co xyweb.doc || :
xyxdvi.doc:; test -d RCS -a -f RCS/xyxdvi.doc,v && co xyxdvi.doc || :


# DEVELOPMENT TARGETS:
#
.PHONY:		Install.macros Install Ftpsrc Ftpdoc Ftp World Minor

Install.macros:
	$(MAKE)          USR=$$HOME/pub			install.macros

Install:
	$(MAKE)          USR=$$HOME/pub			install

Ftpsrc:
	$(MAKE)        MODES='ljfour cx'		\
			MAGS='0 0.5 1 2'		\
		     FTPROOT=$$HOME/public_ftp/TeX	ftpsrc

Ftpdoc:
	$(MAKE)      MODES='ljfour cx'			\
		      MAGS='0 0.5 1 2'			\
		   FTPROOT=$$HOME/public_ftp/TeX	ftpdoc

Ftp:
	$(MAKE)      MODES='ljfour cx'			\
		      MAGS='0 0.5 1 2'			\
		   FTPROOT=$$HOME/public_ftp/TeX	ftp

Www:
	$(MAKE)    WWWROOT=$$HOME/public_html 		install.www

World:
	$(MAKE)      LATEX='time latex' 		\
		     MODES='ljfour cx'			\
		      MAGS='0 0.5 1 2'			world
	mv make.world make.World

TMPFTPROOT = $$HOME/tmp/new-ftp-root

Minor:
	$(MKDIR) $(TMPFTPROOT)
	$(MAKE)      LATEX='time latex' 		\
		     MODES='ljfour cx'			\
		      MAGS='0 0.5 1 2'			\
	           FTPROOT=$(TMPFTPROOT)		world
	mv make.world make.Minor
#
	@echo "Making patch:";\
	 cd $(TMPFTPROOT); \
	 diff -urN $(FTPROOT)/xy-$(VERSION) xy-$(VERSION) > FIX; \
	 n=`cd $(FTPROOT);ls xy$(SHORTVERSION)fix* | wc -w 2>/dev/null`; \
	 n=`expr $$n + 1`; \
	 fix=$(FTPROOT)/xy$(SHORTVERSION)fix`printf '%.2d' $$n`; \
	 cp -vf FIX $$fix; gzip -v9 $$fix
#
	@echo "Updating real ftp archive $(FTPROOT):";\
	 cd $(TMPFTPROOT); \
	 find xy* -type f -print \
	 | while read f;\
	   do cmp -s $$f $(FTPROOT)/$$f\
	      || { echo $$f; $(MKDIR) `dirname $(FTPROOT)/$$f`;\
		   if [ -w $$f ]; then $(INSTALLW) $$f $(FTPROOT)/$$f;\
	           else                $(INSTALL)  $$f $(FTPROOT)/$$f;\
		   fi; };\
	   done
	$(RM) $(TMPFTPROOT)


# LOG
#
# $Log: Makefile,v $
# Revision 3.7  1999/02/16 15:12:50  krisrose
# Interim release (Y&Y fonts now free).
#
# Revision 3.6  1998/03/06 01:28:05  krisrose
# Releasing (with Y&Y fonts).
#
# Revision 3.5  1997/05/28 13:05:01  krisrose
# Fixed missing breaks bug.
#
# Revision 3.4  1997/05/18 03:04:44  krisrose
# Essential bugfixes.
# And movies now included!
#
# Revision 3.3  1996/12/19 17:05:13  krisrose
# Maintenance release!
#
# Revision 3.2  1995/09/19  18:22:27  kris
# Bug fix release.
#
# Revision 3.1  1995/09/05  20:31:32  kris
# Releasing!
#
# Revision 3.0  1995/07/07  20:14:21  kris
# Major release w/new User's Guide!
#
# Revision 2.14  1995/07/06  02:56:02  kris
# Buglets...
#
# Revision 2.13  1995/07/04  15:10:01  kris
# Ready to release v3?
#
# Revision 2.12  1994/10/25  11:46:25  kris
# Interim release just before v3 [works with AMS-LaTeX 1.2]...
#
# Revision 2.11  1994/07/05  10:37:32  kris
# Third 3beta release [bug fixes].
# Experimental graph feature included (for ECCT-94 presentation).
#
# Revision 2.10  1994/06/15  13:35:19  kris
# Second 3beta release [bug fixes].
#
# Revision 2.9  1994/06/09  14:53:07  kris
# Release 3beta.
#
# Revision 2.8  1994/04/08  04:30:00  kris
# Second (bug fix) 3alpha release.
#
# Revision 2.7  1994/03/08  02:06:01  kris
# Release 3alpha.
#
# Revision 2.6.9.1  1994/03/07  04:22:46  kris
# Last internal 3alpha and pre-2.7 release.
#
# MAJOR REORGANISATION for version 2.7...
#
# Revision 2.6  1992/06/24  01:23:34  kris
# Ready to release v.2.6.
#
# Revision 2.5  1992/02/24  03:30:54  kris
# Default magsteps now just 0, 0.5, 1, and 2.
#
# Revision 2.3  1992/01/13  02:12:28  kris
# Fixed installation instructions and other details.
#
# Revision 2.1  1992/01/02  14:54:07  kris
# Release version.
#
# Revision 1.6  1991/12/17  04:51:16  kris
# Version distributed with `final draft' on Usenet.

# Tell Emacs that this is a Makefile and how it is formatted:
# Local Variables:
# mode:fundamental
# fill-prefix:"# "
# fill-column:77
# End:

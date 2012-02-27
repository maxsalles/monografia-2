$!+++
$!
$! DOC2TEX.COM
$!
$! This procedure creates the *.TEX files from the *.DOC files of the XYpic
$! package. It must be run from the XYpic source directory.
$!
$! R.Gaertner, based on personal communication with K.H.Rose
$!
$!---
$ set noon
$!
$! loop over all files
$!
$file_loop:
$ file = f$search("*.doc",1)
$ if file .nes. ""
$ then
$   write sys$output "processing ''file' ..."
$   !
$   ! get the filename and open a temporary work file
$   !
$   name = f$parse(file,,,"NAME")
$   open/write  tmp  'name'.tmp
$   open/read   src  'file'
$   !
$   ! set control flags
$   !
$   hdr  = "TRUE"
$   skip = "FALSE"
$   !
$   ! loop through the source file
$   !
$   line = ""
$loop:
$   read/end=end_loop  src  line
$   if hdr
$   then ! copy the lines from start to the first "\DOCMODE" line
$     if (f$length(line) .ge. 8) .and. (f$extract(0,8,line) .eqs. "\DOCMODE")
$       then hdr  = "FALSE"
$            skip = "TRUE"  ! stop copying
$            goto loop
$     endif
$     ! the first \DOCMODE-line may also indicate the start of the body part
$     if (f$length(line) .ge. 9) .and. (f$extract(0,9,line) .eqs. "\DOCMODE(")
$       then skip = "FALSE" ! start copying
$            goto loop
$     endif
$   else ! extract the lines between "\DOCMODE(" and "\DOCMODE)"
$     if (f$length(line) .ge. 9) .and. (f$extract(0,9,line) .eqs. "\DOCMODE(")
$       then skip = "FALSE" ! start copying
$            goto loop
$     endif
$     if (f$length(line) .ge. 9) .and. (f$extract(0,9,line) .eqs. "\DOCMODE)")
$       then skip = "TRUE" ! stop copying
$            goto loop
$     endif
$   endif
$   !
$   ! skip empty lines
$   !
$   if f$edit(line,"COLLAPSE") .eqs. "" then goto loop
$   !
$   ! skip comment lines (starting with a single percent character)
$   !
$   if  (line .eqs. "%") .or. -
       ((f$length(line) .ge. 2) .and. -
        (f$extract(0,1,line) .eqs. "%") .and. -
        (f$extract(1,1,line) .nes. "%")) then goto loop
$   !
$   ! all preprocessing & checks done, copy the input line
$   !
$   if .not. skip then write  tmp  line
$   goto loop
$   !
$   ! close source & work file
$   !
$end_loop:
$   close  tmp
$   close  src
$   !
$   ! convert the work file to standard text format and delete the work file
$   !
$   if f$search("text.fdl",2) .eqs. ""
$   then create  text.fdl
SYSTEM
	SOURCE                  OpenVMS

FILE
	ORGANIZATION            sequential

RECORD
	BLOCK_SPAN              yes
	CARRIAGE_CONTROL        carriage_return
	FORMAT                  variable
	SIZE                    0

$   endif
$   convert/fdl=text.fdl  'name'.tmp  'name'.tex
$   delete/nolog  'name'.tmp;*
$   !
$   ! process the next source
$   !
$   goto file_loop
$ endif
$ write sys$output "all done"
$!
$! clean up
$!
$ delete/nolog text.fdl;*
$
$ exit
$!
$! End of DOC2TEX.COM

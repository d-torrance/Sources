ACLOCAL_AMFLAGS = -I m4

if ENABLE_FACTORY
  USE_FACTORY = factory
endif

SUBDIRS = resources omalloc $(USE_FACTORY) \
libpolys gfanlib IntegerProgramming \
kernel Singular \
dox emacs redhat desktop

EXTRA_DIST = README README.md README.pkg autogen.sh git-version-gen doxy redhat/singular.spec.in GPL2 GPL3 doc/doc.tbz2

bin_SCRIPTS = libsingular-config

dist-hook:
	$(srcdir)/git-version-gen $(srcdir)/.tarball-git-version > $(distdir)/.tarball-git-version

install-data-local:
	-cat ${top_srcdir}/doc/doc.tbz2| (cd $(datadir)/singular;tar jxf -)
	-mkdir $(datadir)/info
	-mv  $(datadir)/singular/singular.hlp  $(datadir)/info/.

configheaderdir = ${includedir}/singular
nodist_configheader_HEADERS = singularconfig.h
DISTCLEANFILES = $(nodist_configheader_HEADERS)

dist_man1_MANS = doc/Singular.man doc/ESingular.man doc/TSingular.man

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = Singular.pc

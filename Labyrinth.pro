TEMPLATE = subdirs

SUBDIRS = \
	src \
#	Catch2 \
#	QTest

src.subdir = "src"
src.destdir = "."
# Catch2.subdir = "test/Catch2 Test"
# QTest.subdir = "test/QTest Test"

# Catch2.depends = src
# QTest.depends = src

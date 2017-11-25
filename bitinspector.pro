# bitinspector.pro - project file for Bit Inspector
#
# Copyright (C) 2009  Denver Gingerich <denver@ossguy.com>
#
# The contents of this file can be redistributed and/or modified under the
# terms of the GNU General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your
# option) any later version.
#
# This file is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see http://www.gnu.org/licenses/.

QT += widgets

# libbitconvert and libpcre locations; if no ../pcre, use the system libpcre
INCLUDEPATH += ../libbitconvert
LIBS += -L../libbitconvert -lbitconvert -L../pcre -lpcre

# Input
SOURCES += main.cpp bitprocessor.cpp
HEADERS += bitprocessor.h

# Resources
RC_FILE = bitinspector.rc

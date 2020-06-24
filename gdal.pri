#------------------------------------------------------------------------------
#   GDAL LIBRARY
#
#   Info for Windows-msvc:
#   - install gdal (32 or 64 bit) with OSGeo4W: https://trac.osgeo.org/osgeo4w/
#   - add GDAL_PATH to system variables (example: C:\OSGeo4W64)
#   - add OSGeo4W bin directory (example: C:\OSGeo4W64\bin) to system path
#
#------------------------------------------------------------------------------

unix:!macx {
    LIBS += -L/usr/lib -lgdal
    LIBS += -L/usr/lib/x86_64-linux-gnu -lgeos_c

    INCLUDEPATH += /usr/include/gdal
    DEPENDPATH += /usr/include/gdal
}

win32-msvc {
    LIBS += $$(GDAL_PATH)/lib/gdal_i.lib
    LIBS += $$(GDAL_PATH)/lib/geos_c.lib

    INCLUDEPATH += $$(GDAL_PATH)/include
    DEPENDPATH += $$(GDAL_PATH)/include

    PRE_TARGETDEPS += $$(GDAL_PATH)/lib/gdal_i.lib
    PRE_TARGETDEPS += $$(GDAL_PATH)/lib/geos_c.lib
}

win32-g++ {
    # TODO LIB
    INCLUDEPATH += $$(GDAL_PATH)/include
    DEPENDPATH += $$(GDAL_PATH)/include
}

mac {
    LIBS += -framework IOKit
    LIBS += -framework CoreFoundation

    QMAKE_LFLAGS += -F/Library/Frameworks/

    LIBS += -framework GDAL
    LIBS += -framework PROJ
    LIBS += -framework GEOS

    INCLUDEPATH += /Library/Frameworks/GDAL.framework/Headers
    INCLUDEPATH += /Library/Frameworks/PROJ.framework/Headers
    INCLUDEPATH += /Library/Frameworks/GEOS.framework/Headers
}


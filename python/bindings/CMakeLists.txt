# Copyright 2011-2020 Free Software Foundation, Inc.
# Copyright 2013-2021 Sylvain Munaut <tnt@246tNt.com>
#
# This file is part of gr-fosphor
#
# SPDX-License-Identifier: GPL-3.0-or-later

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)


########################################################################
# Python Bindings
########################################################################

list(APPEND fosphor_python_files
    base_sink_c_python.cc
    overlap_cc_python.cc
    python_bindings.cc)

if(ENABLE_GLFW)
    add_definitions(-DENABLE_GLFW)
    list(APPEND fosphor_python_files
        glfw_sink_c_python.cc
    )
endif()

if(ENABLE_QT)
    add_definitions(-DENABLE_QT)
    list(APPEND fosphor_python_files
        qt_sink_c_python.cc
    )
endif()

GR_PYBIND_MAKE(fosphor
   ../..
   gr::fosphor
   "${fosphor_python_files}")

install(TARGETS fosphor_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/fosphor COMPONENT pythonapi)

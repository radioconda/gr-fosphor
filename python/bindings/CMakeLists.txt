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
    glfw_sink_c_python.cc
    qt_sink_c_python.cc
    python_bindings.cc)

GR_PYBIND_MAKE(fosphor
   ../..
   gr::fosphor
   "${fosphor_python_files}")

install(TARGETS fosphor_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/fosphor COMPONENT pythonapi)

/* -*- c++ -*- */
/*
 * Copyright 2013-2021 Sylvain Munaut <tnt@246tNt.com>
 *
 * This file is part of gr-fosphor
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

#include <gnuradio/fosphor/qt_sink_c.h>

#include "base_sink_c_impl.h"

namespace gr {
  namespace fosphor {

    class QGLSurface;

    /*!
     * \brief Qt version of fosphor sink (implementation)
     * \ingroup fosphor
     */
    class qt_sink_c_impl : public qt_sink_c, public base_sink_c_impl
    {
     friend class QGLSurface;

     private:
      QGLSurface *d_gui;

     protected:
      /* Delegated implementation of GL context management */
      void glctx_init();
      void glctx_swap();
      void glctx_poll();
      void glctx_fini();
      void glctx_update();

     public:
      qt_sink_c_impl(QWidget *parent=NULL);

      void exec_();
      QWidget* qwidget();
    };

  } // namespace fosphor
} // namespace gr

/*
 * Author: Sarah Knepper <sarah.knepper@intel.com>
 * Copyright (c) 2015 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <iostream>

#include "ttp223.hpp"
#include "upm_utilities.h"

int
main(int argc, char** argv)
{
    // This example uses GPIO 0
    //! [Interesting]

    // Create the TTP223 touch sensor object using GPIO pin 0
    upm::TTP223 touch(0);

    // Check whether or not a finger is near the touch sensor and
    // print accordingly, waiting one second between readings
    while (1) {
        if (touch.isPressed()) {
            std::cout << touch.name() << " is pressed" << std::endl;
        } else {
            std::cout << touch.name() << " is not pressed" << std::endl;
        }
        upm_delay(1);
    }

    // Delete the touch sensor object
    //! [Interesting]

    return 0;
}
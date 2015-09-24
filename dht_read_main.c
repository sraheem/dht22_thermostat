// Copyright (c) 2014 Adafruit Industries
// Author: Tony DiCola

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "Raspberry_Pi_2/pi_2_dht_read.h"
#include <stdio.h>

void main()
{
int sensor=22, pin=12, result;
float temperature=0, humidity=0;
result = pi_2_dht_read(sensor, pin, &humidity, &temperature);
printf("%f, %f",humidity,temperature);
}

// Boilerplate python module method list and initialization functions below.
/*
static PyMethodDef module_methods[] = {
    {"read", Raspberry_Pi_2_Driver_read, METH_VARARGS, "Read DHT sensor value on a Raspberry Pi 2."},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initRaspberry_Pi_2_Driver(void)
{
    Py_InitModule("Raspberry_Pi_2_Driver", module_methods);
}
*/

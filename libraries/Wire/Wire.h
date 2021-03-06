/*
  TwoWire.h - TWI/I2C library for Arduino & Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
  Revised 31 May 2009 Christopher K. Johnson.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>

#define BUFFER_LENGTH 32

#define STANDARD 100000L
#define FAST 400000L

class TwoWire
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t*, int);
  public:
    TwoWire();
    void begin();
    void begin(uint8_t);
    void begin(int);
    long unsigned int setSpeed(long unsigned int);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    void beginTransmissionAt(uint8_t,uint8_t);
    void beginTransmissionAt(int,int);
    void beginTransmissionAt2(uint8_t,int);
    void beginTransmissionAt2(int,int);
    uint8_t endTransmission(void);
    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFromAt(uint8_t, uint8_t, uint8_t);
    uint8_t requestFromAt(int, int, int);
    uint8_t requestFromAt2(uint8_t, int, uint8_t);
    uint8_t requestFromAt2(int, int, int);
    void send(uint8_t);
    void send(uint8_t*, uint8_t);
    void send(int);
    void send(char*);
    uint8_t available(void);
    uint8_t receive(void);
    void onReceive( void (*)(int) );
    void onRequest( void (*)(void) );
};

extern TwoWire Wire;

#endif


/**
 * @file arduino_serial.hpp
 * @author Akari (masiro.to.akari@gmail.com)
 * @brief
 * @version 0.23.2
 * @date 2023-02-23
 *
 * @copyright Copyright (c) 2023 / MaSiRo Project.
 *
 */
#ifndef ARDUINO_FUNC_COMMUNICATION_ARDUINO_SERIAL_HPP
#define ARDUINO_FUNC_COMMUNICATION_ARDUINO_SERIAL_HPP

#include "../arduino_types.hpp"
#define SERIAL_BUFFER_SIZE 255
#include <stdio.h>
#include <stdlib.h>

class Serial_STAB {
private:
    int peek_buffer;

public:
    Serial_STAB();
    void begin(unsigned long);
    void begin(unsigned long, uint8_t);
    void end(void);

    virtual int available(void);
    virtual int peek(void);
    virtual int read(void);
    virtual int availableForWrite(void);
    virtual void flush(void);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *, size_t);
    // using Print::write; // pull in write(str) and write(buf, size) from Print
    operator bool();
    void println(const char *format, ...);
    void print(const char *format, ...);

    volatile uint8_t _rx_buffer_head             = 0;
    volatile uint8_t _rx_buffer_tail             = 0;
    unsigned char _rx_buffer[SERIAL_BUFFER_SIZE] = { 0 };

    // This method allows processing "SEND_BREAK" requests sent by
    // the USB host. Those requests indicate that the host wants to
    // send a BREAK signal and are accompanied by a single uint16_t
    // value, specifying the duration of the break. The value 0
    // means to end any current break, while the value 0xffff means
    // to start an indefinite break.
    // readBreak() will return the value of the most recent break
    // request, but will return it at most once, returning -1 when
    // readBreak() is called again (until another break request is
    // received, which is again returned once).
    // This also mean that if two break requests are received
    // without readBreak() being called in between, the value of the
    // first request is lost.
    // Note that the value returned is a long, so it can return
    // 0-0xffff as well as -1.
    int32_t readBreak();

    // These return the settings specified by the USB host for the
    // serial port. These aren't really used, but are offered here
    // in case a sketch wants to act on these settings.
    uint32_t baud();
    uint8_t stopbits();
    uint8_t paritytype();
    uint8_t numbits();
    bool dtr();
    bool rts();
    enum
    {
        ONE_STOP_BIT          = 0,
        ONE_AND_HALF_STOP_BIT = 1,
        TWO_STOP_BITS         = 2,
    };
    enum
    {
        NO_PARITY    = 0,
        ODD_PARITY   = 1,
        EVEN_PARITY  = 2,
        MARK_PARITY  = 3,
        SPACE_PARITY = 4,
    };
};

extern Serial_STAB Serial;
extern Serial_STAB Serial1;
extern Serial_STAB Serial2;
extern Serial_STAB Serial3;

#endif

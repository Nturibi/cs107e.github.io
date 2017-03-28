this contains the code from the second interrupt lecture:
	race-condition-dre: demonstrates a bunch of race conditions.
	circular-buffer: shows how to implement (and somewhat test) a simple
		circular buffer.
	gprof: shows how to use timer interrupts, alloc, and the circular
	buffer to do statistical profiling.   very little can go very far
	where there is not a huge system in your way.


the rest of the directory contains examples from phil's previous lecture.

-------------------------------------------------------------------

This directory contains sample code for generating and handling interrupts
on the Raspberry Pi. It includes examples of why you want interrupts as
well as working interrupt code.

blocking_button: application that detects a falling clock edge on GPIO pin
                 21 and updates an HDMI screen output. Because screen refresh
                 is slow, pressing the button multiple times quickly will
                 result in missed edges.

blocking_keyboard: application that reads PS2 scan codes from a keyboard using
                 direct GPIO read/write and displays characters on the screen.
                 Because screen refresh is slow, typing quickly will lose 
                 characters or result in duplicate characters.

interrupts: application that uses interrupts to detect falling edges on GPIO
                 pin 23. The main loop increments a counter by 1, and an interrupt
                 increments it by 0x1000. Typing a regular key therefore results
                 in 33 interrupts (key code, release code, key code, 11 bits
                 per code). Displays state of internal detection registers,
                 pending interrupts, etc.


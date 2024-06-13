## Overview

TinyJiggle is a simple mouse jiggler that will work with any [ATmega32U4 or SAMD
devices](https://www.arduino.cc/reference/en/language/functions/usb/mouse/).

- Every second there is a 2% chance the mouse will jiggle.
- There is about a 70% chance of a jiggle occurring within one minute.
- If there is no jiggle within 5 minutes, it will force a jiggle.

The "jiggle" is a very fast movement of 2 pixels and then back 2 pixels. This
movement is enough to keep the computer from going idle while being completely
unnoticable and will not impact regular usage of the mouse.

## Usage

Copy the code from [tinyjiggle.ino](/tinyjiggle.ino), or clone the repo:

```sh
git clone https://github.com/nronzel/TinyJiggle.git
```

> [!NOTE]
> This was only tested using the Arduino IDE.
>
> The device I used was the [DFROBOT Beetle](https://www.dfrobot.com/product-1075.html).

- Plug in your ATmega32U4 or SAMD device
- Connect to the device in the Arduino IDE
- Ensure the Mouse library is installed
  - Tools > Manage Libraries
  - Search for "Mouse" and install the library called "Mouse" by Arudino
  - Install latest version
- Open the sketch (or paste the code if you just copied it) and upload it to
  the device

Once the sketch has been uploaded you can plug the device into whatever computer
you'd like to use the jiggler on.

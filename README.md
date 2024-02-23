# PROJECT

---

![text](crystos.webp)

---

## PRESENTATION

crystos is a simple crystal oscillator module emulation.

---

## PREREQUISITES

* C11 compiler

---

## SUPPORTED PLATFORMS

- [ ] Windows
- [X] Linux
- [X] macOS

---

## HOW TO USE

```c
#define CRYSTOS_IMPLEMENTATION
#include <crystos.h>

unsigned long long counter = 0;

void update(void) {
    ++counter;
}

int main(void) {
	                   // in Hz
    Clock nesClock = {.frequency = 1798773 }; // try tweaking this
    while(1) {
	tick(&nesClock, &update);
	printf("cycles passed: %llu\n", counter);
    }
}
```

---

## TODO

- [ ] Get frequency and Get ticks functions
- [ ] Cross-platform support

---

## REFERENCES

- [Ben Eater's clock module simulator](https://www.youtube.com/watch?v=kRlSFm519Bo)

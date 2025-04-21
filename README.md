# Tutorial 9 - Phone Call System

### Tutorial 9 worksheet available via this link

---

[📄 View Tutorial 9 Instructions (PDF)](Tutorial_9.pdf)

### Exercise Implementation Details

This project implements a phone call management system with the following components:

1. **Date and Time Management** ([date.h](exercise2/date.h), [date.cpp](exercise2/date.cpp))

   - Handles date and time operations
   - Provides current date/time functionality

2. **Phone Call System** ([phone_call.h](exercise2/phone_call.h), [phone_call.cpp](exercise2/phone_call.cpp))
   - Base class `PhoneCall` with common functionality
   - Two types of calls:
     - `IncomingPhoneCall`: Fixed rate of 2 DA per call
     - `OutgoingPhoneCall`: Rate of 10 DA per minute

### Building the Project

```sh
cd exercise2
mkdir build && cd build
cmake ..
make
```

### Running the Program

```sh
./exercise2
```

### License

This project is licensed under the [MIT License](LICENSE).

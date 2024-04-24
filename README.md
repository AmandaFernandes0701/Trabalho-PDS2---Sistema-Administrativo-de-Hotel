# General Instructions about the System
## Hotel System
### This system aims to manage a reservation system in a hotel.
### The system allows for some functionalities, such as:
- Guests can schedule or cancel a reservation.
- Employees can check reservations on a specific date, check available rooms on another date, or check the information of a particular guest.

## To compile the program and tests
- In the root folder of the program, type the command `make` in the terminal to compile all the implemented code, which also includes the unit tests.

## To run the program
- In the root folder of the program, where the executable named `trabalho` was generated, type `./trabalho` in the terminal to run the program.

## To run the tests
- In the root folder of the program, where the executable named `testar` was generated, type `./testar` in the terminal to run all unit tests and view the result.

## To generate the Doxygen of the program
- After installing Doxygen.
    - For Windows, you can use this [link](https://www.doxygen.nl/files/doxygen-1.9.5-setup.exe).
- In the root folder of the program, generate Doxygen using the configuration file `Doxyfile` with the following command: `doxygen Doxyfile`.
- A folder named **html** will be created.
- Inside the **html** folder, the `index.html` file needs to be opened to navigate through the generated documentation of the entire system implementation.

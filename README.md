# Program Description

The program will read input files, process the data, and generate two output files:

- **output_comenzi.txt** – Contains details about each customer's orders, including:
  - Customer ID and name
  - Order date
  - Ordered products (name, unit price, and total cost per product)
  - Total order amount for each customer
  
- **output_stoc_ramas.txt** – Displays available products and the remaining stock after processing all orders, along with each product’s price. This file serves as an updated inventory, showing the remaining stock.

## Reading and Storing Data
Implement functionalities to read product and customer information from the `produse.txt` and `clienti.txt` files and store them using classes.

## Processing Orders
Program the system to check the stock and update the remaining quantities after each order is processed.

## Generating Output Files
The program must generate two output files:
- **output_comenzi.txt** – containing details about each customer's orders.
- **output_stoc_ramas.txt** – showing the remaining stock for each product.

---

## Functions

Here are all the necessary functions to solve the problem, such as checking if a file is empty, reading stock data, reading customer data, a function to display stock, and one to display both customers and stock, followed by the function that processes all orders and makes stock changes.

### File Size Check Function

The file size check function works as follows:

- It is a boolean type because we want to return `true` if the file is empty, and `false` otherwise.
- The first line of the function opens the file in binary mode and moves the cursor to the last position, not the first, as it usually happens.
- The `ftellg` function tells us the position where the cursor is, and if it’s 0, that means the file is empty.

### File Reading Functions

We made sure that there are no issues with newline characters and the reading of characters and strings.

On lines 43 and 44, a problem occurred due to the IDE. In Visual Studio 2022, when I only used `file.ignore()`, it created the output files exactly as in those on Git, but I didn't get full points. When I switched to Visual Studio Code and ran the program, the files were created incorrectly. So, I added another `file.ignore()`, because I noticed that instead of reading a name, it was reading a newline.

### Stock Processing Function

This function simply loops through all the customer orders and subtracts from the stock of the products that were bought.

---

## Main

I initialized the read and display files, then handled the different scenarios that could happen:

1. **If both input files were empty**, I displayed an appropriate message in both output files.
2. **If the customer file was empty**, I worked only with the products and displayed the stock in the corresponding output file.
3. **If both input files contained data**, I solved the task. The products were already read in the second case, so I only needed to read the orders. Once I finished reading all the data, I called the `processStock` function, which practically solved the task, and then I called the display function. Finally, I released the memory used by the main vectors and closed the files.


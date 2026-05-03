# Inventory Manager 

Student: Karine Vieira
Project: Inventory Manager

## Why a Inventory Manager?

It is pertinent if you have a bussiness and want to keep track of your inventory. You can track sales, add items, have an idea how much your stock is worth and so forth. 

### What it does?

- Shows a menu with options for you to:
* Add Items to your inventory (name, SKU, quantity, the price (per item), the reorder point (when the system should warn the user to reorder item that are running low on stock)).
* You can update the quantity in case you put the wrong number or if you received more of that item.
* You can generate a sale of a specific product (the product needs to be on the list). It will calculate how much revenue the store made based on the price and quantity sold. This feature also decreases the quantity in the inventory to keep the system more accurate.
* The Sales report will show all the items, how many were sold, and how much revenue was earned.
* SearchByName allows the user to search the product and display it features. 
* The last option in the menu is for the user to exit the program. 

#### How to use the features?

- The program is very straight forward and will prompt the user with the exact information they need to input for the system to work. 
- As long as the user stays in the bounds of the menu, does not type a negative number, or letters where they should not go the system will work properly. 
- The program handles the following edge cases:
* negative number on the quantity (quantity cannot be negative).
* changes all the characters to lower case on the searchByName function so it can match the string easier 
* makes sure that the store is not selling more products than it has in the inventory

##### Notes

- I added an output example as a .txt file just to make sure you can see the program working properly.
- I feel like I over complicated some features and I still have a hard time understanding references.
- This is the first time I work with vectors (in the other assignments I was working with arrays that had a specific size but here I left it to the user to just add as many products as they wish). 
- Looking forward to the code review so I can get some insight on how to make the code more clear (maybe less complicated?!)



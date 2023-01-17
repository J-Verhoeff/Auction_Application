# Auction App

### Description

This program called "Auction" is a user based system. This program will interact with the user on the command line to sell and bid on items in an auction applicaiton, similar to that of Ebay. The user will be able to perform transactions pertaining to posting a new item, biding on an existing item, and adding credit to their account.

This program conatains user account with different privileges. An admin user can create and delete users, and will have special privileges with buying and selling. Where as buy-standard can only bid, sell-standard can only sell and full-standard can but and sell.

All of the items, user data, and session transactions are stored in text files that will be handled by the back-end of the program

Program is written in C++ and compiled using windows

To compile:

```batch
make
```

To run:

```batch
auction resources/availableItems.txt resources/currentUserAccounts.txt
```

#### Testing

To run output generator test script:

```batch
scriptGenerate.bat
```

To run output compare test script:

```batch
scriptCompare.bat
```

Test results will be displayed in:

```batch
tests/results/results.log
```

### Authors: Joshua Verhoeff, Peter Nagy

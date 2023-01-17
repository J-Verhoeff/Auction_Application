@echo off
Rem Takes each file in the inputs directory and inputs the content into the auction program.
Rem Then, the output from the program is directed to files named identically in the outputs directory.
if not exist "tests\outputs\" mkdir "tests\outputs"
FOR %%G in ("tests/inputs/*.txt") do (
    echo Running test: %%G
    auction resources/availableItems.txt resources/currentUserAccounts.txt < "tests/inputs/%%G" > "tests/outputs/%%G"
)

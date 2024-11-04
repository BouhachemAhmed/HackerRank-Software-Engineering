-- SQL query to filter and sort customers based on name length and alphabetical order

SELECT 
    ID,                      -- Selects the ID of the customer
    FIRST_NAME,              -- Selects the first name of the customer
    LAST_NAME                -- Selects the last name of the customer
FROM 
    CUSTOMER                 -- Specifies the table we are querying from
WHERE 
    LENGTH(CONCAT(FIRST_NAME, LAST_NAME)) < 12  -- Filters rows where combined name length is less than 12
ORDER BY 
    LENGTH(CONCAT(FIRST_NAME, LAST_NAME)) ASC,  -- Sorts by the length of the combined name
    CONCAT(FIRST_NAME, LAST_NAME) ASC,          -- Sorts alphabetically by combined name (case insensitive)
    ID ASC;                                     -- Finally, sorts by ID in ascending order

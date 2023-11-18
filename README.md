# Cleison CLI

The Cleison CLI program is a simple command-line tool designed for building JSON files explicitly, intended for educational purposes only. The name "Cleison" is a combination of "CLI" (Command-Line Interface) and JSON, emphasizing its focus on creating JSON data structures. This tool allows users to interactively input key-value pairs, which are then used to generate a JSON file.

## How to Use

To use the Cleison CLI program, follow these steps:

### Creating JSON

Run the program and choose option 1 to create a JSON file. Follow the prompts to input field names and values interactively. The program will continue to prompt for additional entries until you choose to stop. After entering the data, specify the desired file name (without the ".json" extension), and the program will generate the JSON file in the current directory.

```bash
$ ./cleison
1 - Create JSON
2 - Read JSONs

1

Input key: name
Input value: John
Want to continue? (y/n): y

Input key: lastName
Input value: Doe
Want to continue? (y/n): n

Choose a beautiful name for your file: me
Saved your new JSON to me.json
```

### Reading JSONs

Choose option 2 to view existing JSON files in the current directory. The program will display a list of available files, and you can choose one to view its contents.

```bash

$ ./cleison
1 - Create JSON
2 - Read JSONs

2

Available JSON files:
me.json


Choose one of the files above (only the filename without the extension): me
{
	"name": "John",
	"lastName": "Doe"
}
```

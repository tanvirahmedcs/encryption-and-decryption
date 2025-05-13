# File Encryption Tool in C

This is a simple command-line file encryption and decryption tool written in C. It uses a basic XOR cipher with a user-provided key to encrypt or decrypt files.

## Usage

Compile the program using:

```
gcc -o encryptor encryptor.c
```

Run the program with the following syntax:

```
./encryptor <encrypt|decrypt> <input_file> <output_file> <key>
```

- `encrypt` or `decrypt`: Mode to specify whether to encrypt or decrypt the input file.
- `input_file`: Path to the input file to be encrypted or decrypted.
- `output_file`: Path where the output file will be saved.
- `key`: The encryption/decryption key (a string).

## Example

To encrypt a file:

```
./encryptor encrypt secret.txt secret.enc mypassword
```

To decrypt a file:

```
./encryptor decrypt secret.enc secret_decrypted.txt mypassword
```

## Notes

- This tool uses a simple XOR cipher and is not suitable for strong security needs.
- Use a strong and secret key to protect your data.

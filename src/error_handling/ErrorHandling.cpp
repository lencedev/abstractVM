/*
** EPITECH PROJECT, 2023
** B-SYN-400-MPL-4-1-abstractVM-owen1.bolling
** File description:
** error_handling
*/

#include <error_handling.hpp>
#include <Exception.hpp>
#include <include.hpp>
#include <iostream>
#include <string>

void avm_file(int ac, const string &filename)
{
    string extension = ".avm";
    if (filename.length() < extension.length() ||
        filename.substr(filename.length() - extension.length()) != extension)
            throw FileAvmError();
    ifstream avmFile(filename);
    if (!avmFile.is_open())
        throw OpenFileError();
    if (ac < 2) {
        throw UsageError();
    }
}


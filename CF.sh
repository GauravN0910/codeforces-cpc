#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <destination_path> <new_filename>"
    exit 1
fi

destination_path="$1"
new_filename="$2"
template_file="Template.cpp"

if [ ! -f "$template_file" ]; then
    echo "Error: $template_file not found!"
    exit 1
fi

if [ ! -d "$destination_path" ]; then
    mkdir -p "$destination_path"
fi

cp "$template_file" "$destination_path/$new_filename"

echo "File created at $destination_path/$new_filename"


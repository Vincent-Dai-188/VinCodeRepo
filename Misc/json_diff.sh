#!/bin/bash
#
# REF: https://stackoverflow.com/questions/31930041/using-jq-or-alternative-command-line-tools-to-compare-json-files
#
if (( $# < 2 )); then
    echo "Usage: $0 <json_file1> <json_file2>"
    exit 1
fi

file1=$1
file2=$2

if [ ! -f "${file1}" ] || [ ! -f "${file2}" ]; then
    echo "'${file1}' or '${file2}' not found!"
    exit 2
fi

diff \
<(jq -S 'def post_recurse(f): def r: (f | select(. != null) | r), .; r; def post_recurse: post_recurse(.[]?); (. | (post_recurse | arrays) |= sort)' "${file1}") \
<(jq -S 'def post_recurse(f): def r: (f | select(. != null) | r), .; r; def post_recurse: post_recurse(.[]?); (. | (post_recurse | arrays) |= sort)' "${file2}")

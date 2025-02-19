#!/usr/bin/env dash

# Check if a folder does not comply with the file structure.

main() {
    echo "linting tests"

    for question in *
    do
        [ -d "$question" ] || continue

        if ! has_tags "$question"
        then
            echo "no tags for $question"
            return 1
        elif ! has_edge "$question"
        then
            echo "no edge for $question"
            return 2
        fi
    done

    echo "all tests have been successfully linted"
}

has_tags() {
    # check a question has at least one tag
    question="$1"

    tags="$(printf "$question" | cut -d ' ' -f2)"
    # should be a non-empty string
    [ -n "$tags" ]
    return $?
}

has_edge() {
    # check a question has a write-up file about the edge

    question="$1"

    # if there are no markdown files, the glob won't be expanded
    [ ! "$question"/*md = "$question/*md" ]
}

main
exit $?

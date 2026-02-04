#!/bin/bash

# exit if variables are not set
set -u


exit_code=0
for file in $1/test_* ; do
	./$file
	tmp_exit_code=$?
	if [[ $tmp_exit_code -gt 0 ]]; then
		exit_code=$tmp_exit_code
	fi
done

exit $exit_code

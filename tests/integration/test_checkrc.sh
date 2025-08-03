#!/bin/sh

# Test valid configuration
echo "Testing valid rc.conf..."
./checkrc tests/integration/test_files/valid_rc.conf
if [ $? -ne 0 ]; then
    echo "ERROR: Valid configuration test failed"
    exit 1
fi

# Test invalid configuration
echo "Testing invalid rc.conf..."
./checkrc tests/integration/test_files/invalid_rc.conf
if [ $? -eq 0 ]; then
    echo "ERROR: Invalid configuration test failed"
    exit 1
fi

echo "All integration tests passed successfully"
exit 0

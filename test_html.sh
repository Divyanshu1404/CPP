#!/bin/bash
echo "Running HTML validation test..."
tidy -errors -q index.html
if [ $? -eq 0 ]; then
  echo "HTML validation passed!"
else
  echo "HTML validation failed!"
  exit 1
fi

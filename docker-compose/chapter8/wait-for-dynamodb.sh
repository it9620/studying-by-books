#!/bin/sh
set -e

until curl -f http://dynamodb:8000; do
# until curl -f http://dynamodb:8001; do
# until curl -f http://localhost:8000; do
  echo "DynamoDB is unavailable - sleeping"
  sleep 5
done

echo "DynamoDB is up - executing command"
exec "$@"

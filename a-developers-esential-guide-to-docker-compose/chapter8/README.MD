# Chapter 8

```sh
docker compose -f docker-compose.yaml \
    -f newsletter-lambda/docker-compose.yaml \
    build --no-cache

docker compose -f docker-compose.yaml \
    -f newsletter-lambda/docker-compose.yaml \
    up

curl -XPOST \
    "http://localhost:8080/2015-03-31/functions/function/invocations" \
    -d '{"email":"john@doe.com","topic":"Books"}' \
    "You have been subscribed to the Books newsletter"
```

```sh
docker compose -f docker-compose.yaml \
    -f newsletter-lambda/docker-compose.yaml \
    -f s3store-lambda/docker-compose.yaml \
    -f sqs-to-lambda/docker-compose.yaml \
    build

docker compose -f docker-compose.yaml \
    -f newsletter-lambda/docker-compose.yaml \
    -f s3store-lambda/docker-compose.yaml \
    -f sqs-to-lambda/docker-compose.yaml \
    up
```

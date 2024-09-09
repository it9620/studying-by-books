# Remarsk

In the book there is a command to run another redis instance by docker (the first one were runned by docker compose):

```sh
docker run --rm -it --entrypoint bash redis -c 'redis-cli -h host.docker.internal -p 6379'
```

you can get an error like `Could not connect to Redis at host.docker.internal:6379: Name or service not known`.

The error Could not connect to Redis at host.docker.internal:6379: Name or service not known indicates that the DNS name host.docker.internal is not recognized by Docker. This issue usually occurs on Linux systems, as host.docker.internal is natively supported only in Docker for Windows and macOS.

So you can troubleshoot this problem by running coomand"

```sh
docker run --rm -it --network host redis redis-cli -h localhost -p 6379
```

Explanation:
--network host: Allows the container to use the host's networking stack, so you can access services running on the host machine without needing special DNS names like host.docker.internal.
-h localhost: This connects the Redis client to localhost, which refers to the host machine when using host network mode.

So to build and run a docker on linux we need execute:

```sh
# build
dockebuild . -t task-manager:0.1
# run
docker run --rm -it --network host -p 8080:8080 --env REDIS_HOST=localhost:6379 task-manager:0.1
```

To list docker networks run:

```sh
docker network ls
# it will list networks one of wich will be with name `chapter2_default` - it the network of redis container
```

And then run docker container:

```sh
docker run --rm -p 8080:8080 --env REDIS_HOST=redis:6379 --network=chapter2_default task-manager:0.1
```

---

## Just notes

HMSET task:8b171ce0-6f7b-4c22-aa6f-8b110c19f83 id 8b171ce0-6f7b-4c22-aa6f-8b110c19f83 Name "A task" Description "A task that need tove executed at the timestamp specified" Timestamp 1645275972000

HGETALL task:8b171ce0-6f7b-4c22-aa6f-8b110c19f83

docker run --rm -p 8080:8080 --env REDIS_HOST=host.docker.internal:6379 task-manager:0.1

docker run --rm -it --network host -p 8080:8080 --env REDIS_HOST=localhost:6379 task-manager:0.1

docker run --rm -p 8080:8080 --env REDIS_HOST=redis:6379 --network=chapter2_default task-manager:0.1
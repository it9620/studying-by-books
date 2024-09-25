# Chapter 3

## Connect volumes to container

```sh
docker volume create example-volume
docker volume ls --filter="name=example-volume" --format='{{json .}}'

docker run -it --rm --name example-volume-container --mount source=example-volume,target=/storage bash
# echo some-text > /storage/data-file.txt
# cat /storage/data-file.txt 
# exit

docker run -it --rm --name second-volume-container --mount source=example-volume,target=/storage bash
# cat /storage/data-file.txt 

docker inspect second-volume-container --format '{{json .Mounts}}'
```

## Shared volume

```sh
docker run -it --rm --name container-2 --mount source=example-volume,target=/storage bash -c "for i in \$(seq 1 1 100000); do echo \$HOSTNAME \$i >> /storage/\$HOSTNAME.txt; done"

docker run -it --rm --name container-1 --mount source=example-volume,target=/storage bash -c "for i in \$(seq 1 1 100000); do echo \$HOSTNAME \$i >> /storage/\$HOSTNAME.txt; done"

docker run -it --rm --name container-1 --mount source=example-volume,target=/storage bash
```

## Readonly volumes

```sh
docker run -it --rm --name read-only-volume-container --mount source=example-volume,target=/storage,readonly bash
# cat /storage/data-file.txt 
# touch /storage/test.txt
# exit
```

## Volume drivers

```sh
docker volume inspect example-volume

sudo cat /var/lib/docker/volumes/example-volume/_data/data-file.txt
```

## Deocker networks

```sh
docker network ls

# Bridge network:
docker run --rm -p 8080:80 --name nginx-compose nginx

docker inspect --format '{{json .NetworkSettings.Networks}}' nginx-compose

docker network ls --filter ID=$NETWORK_ID

# Host network:
docker run --rm --network host --name host-nginx nginx

docker run -it --rm --network host --name nginx-wget bash
# wget -O- localhost:80
# exit

# Overlay network
```

## Determine networks in compose

```sh
docker network ls --filter name=chapter2_default
```

---
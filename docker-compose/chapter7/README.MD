# Chapter 7

```sh
docker compose -f base-compose.yaml \
    -f monitoring/docker-compose.yaml \
    -f events-service/docker-compose.yaml \
    -f location-service/docker-compose.yaml \
    -f task-manager/docker-compose.yaml \
    up

# with hoverfly:
docker compose -f base-compose.yaml \
    -f monitoring/docker-compose.yaml \
    -f events-service/docker-compose.yaml \
    -f location-service/docker-compose.yaml \
    -f task-manager/docker-compose.yaml \
    -f hoverfly/docker-compose.yaml \
    up

# with hoverfly capture:
docker compose -f base-compose.yaml \
    -f monitoring/docker-compose.yaml \
    -f events-service/capture-traffic-docker-compose.yaml \
    -f location-service/docker-compose.yaml \
    -f task-manager/capture-traffic-docker-compose.yaml \
    -f hoverfly/docker-compose.yaml \
    up

# Export JSON by howerfly
curl http://localhost:8888/api/v2/simulation

# export location service
cd location-service
curl --location --request GET \
    'http://localhost:8888/api/v2/simulation?urlPattern=location-service:8080' \
    > location-simulation.json

cd monitoring
curl --location --request GET \
    'http://localhost:8888/api/v2/simulation?urlPattern=push-geteway:9091' \
    > push-gateway-simulation.json


# location service imitation:
docker compose -f base-compose.yaml \
    -f task-manager/docker-compose.yaml \
    -f location-service/mock-location-service.yaml \
    up

# push-geteway service imitation:
docker compose -f base-compose.yaml \
    -f events-service/docker-compose.yaml \
    -f monitoring/mock-push-gateway.yaml \
    up
```

---

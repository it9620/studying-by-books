# RabitMQ Cookbook

Pull the RabbitMQ immage

```sh
docker pull rabbitmq

docker run -d --name rabbitmq -p 5672:5672 -p 15672:15672 rabbitmq:management

# Open in browser: login/pass: guest / guest
http://localhost:15672/

```

## For Python

```sh
pip install pika
```

---

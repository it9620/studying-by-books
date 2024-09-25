# Book info

Book name:

A Developer's Essential Guide to Docker Compose:
Symplify the development and orchestration of multi-container applications

Author:
Emmanouil Gkatziouras

## Install Go

Go to the (page)[https://go.dev/doc/install]. Look for install package.
On linux you just can check if the last version match in package repository.

## Commands

Create a task:

```sh
curl --location --request POST 'localhost:8080/task/' \
--header 'Content-Type: application/json' \
--data-raw '{ "id": "8b171ce0-6f7b-4c22-aa6f-8b110c19f83a", "name": "A task", "description": "A task that need to be executed at the timestamp specified", "timestamp": 1645275972000 }'
```

Get all the tasks:

```sh
curl --location --request GET 'localhost:8080/task'
```

Get a concrete task with defined id:

```sh
curl --location --request GET 'localhost:8080/task/8b171ce0-6f7b-4c22-aa6f-8b110c19f83a'
```

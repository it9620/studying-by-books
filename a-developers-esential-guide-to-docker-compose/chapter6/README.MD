# Chapter 6

```sh

go get github.com/prometheus/client_golang/prometheus &&
go get github.com/prometheus/client_golang/prometheus/promauto &&
go get github.com/prometheus/client_golang/prometheus/promhttp

# For location-service:
go mod tidy
go get github.com/go-playground/validator/v10@v10.20.0
go get golang.org/x/net/idna@v0.29.0
```


PromQL queries:
rate(promhttp_metric_handler_requests_total[10m])
rate(task_event_processing_total[10m])


---

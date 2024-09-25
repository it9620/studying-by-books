# FROM amazon/aws-lambda-go:latest as build

# RUN yum install -y golang
# RUN go env -w GOPROXY=direct
# # cache dependencies

# COPY go.mod ./
# COPY go.sum ./

# RUN go mod download

# COPY *.go ./

# RUN go build -o /main

# FROM amazon/aws-lambda-go:latest
# COPY --from=build /main /var/task/main

# CMD [ "main" ]


# Build Stage
FROM golang:1.23 AS builder

# Set the working directory
WORKDIR /app

# Copy go.mod and go.sum
COPY go.mod go.sum ./

RUN go version

# Download dependencies
RUN go mod download

# Copy the source code
COPY *.go ./

# Build the application
RUN go build -o main .

# Final Stage
FROM amazon/aws-lambda-go:latest

# Copy the built binary from the builder stage
COPY --from=build /main /var/task/main

# Command to run the Lambda function
CMD [ "main" ]
# Stage 1: Build stage
# Use the official Go image for amd64
FROM golang:1.23 as build

WORKDIR /app

# Set up Go module dependencies
COPY go.mod ./
COPY go.sum ./
RUN go mod download

# Copy the application code
COPY *.go ./

# Build the Go binary for Linux (required for AWS Lambda) and amd64 architecture
RUN go build -o /main

# Stage 2: AWS Lambda image
# Ensure this is for amd64 as well
FROM --platform=linux/arm64 amazon/aws-lambda-go 

# Copy the built binary from the build stage
COPY --from=build /main /var/task/main

# Specify the Lambda function handler
CMD [ "main" ]


# # Stage 1: Build stage
# # Use the official Go image for amd64
# FROM --platform=linux/amd64 golang:1.23 as build

# WORKDIR /app

# # Set up Go module dependencies
# COPY go.mod ./
# COPY go.sum ./
# RUN go mod download

# # Copy the application code
# COPY *.go ./

# # Build the Go binary for Linux (required for AWS Lambda) and amd64 architecture
# RUN GOOS=linux GOARCH=amd64 go build -o /main

# # Stage 2: AWS Lambda image
# # Ensure this is for amd64 as well
# FROM --platform=linux/amd64 amazon/aws-lambda-go:latest  

# # Copy the built binary from the build stage
# COPY --from=build /main /var/task/main

# # Specify the Lambda function handler
# CMD [ "main" ]



# FROM --platform=linux/arm64 amazon/aws-lambda-go:latest as build

# RUN yum install -y golang
# RUN go env -w GOPROXY=direct

# COPY go.mod ./
# COPY go.sum ./

# RUN go mod download

# COPY *.go ./

# RUN go build -o /main

# FROM amazon/aws-lambda-go:latest
# COPY --from=build /main /var/task/main

# CMD [ "main" ]
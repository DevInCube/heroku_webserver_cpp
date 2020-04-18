# Usage

## Local Docker

Build Docker image:

```sh
docker build . -t mybotapp
```

Run Docker container based on the image:

```sh
docker run -it -p 3000:3000 mybotapp:latest
```

## Publish to Heroku

Create an app using Heroku CLI:

```sh
heroku container:login
heroku create mybotapp
```

Push and release changes:

```sh
heroku container:push web --app mybotapp
heroku container:release web --app mybotapp
```

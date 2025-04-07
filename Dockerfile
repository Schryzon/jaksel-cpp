# Use an official C++ build environment as a base image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /app

# Copy your project files into the container
COPY . .

# Compile your interpreter (assume your main file is JakselInterpreter.cpp)
RUN g++ -std=c++17 -o jaksel_interpreter JakselInterpreter.cpp

# Define the command to run your interpreter when the container starts
CMD ["./jaksel_interpreter"]
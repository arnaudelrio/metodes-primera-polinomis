FROM cristiangreco/pdflatex:latest

# install gnuplot
RUN apt-get update && apt-get install -y gnuplot build-essential && rm -rf /var/lib/apt/lists/*

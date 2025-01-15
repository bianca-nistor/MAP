FROM gcc:latest
WORKDIR /MAP
COPY proiect.c .
RUN gcc proiect.c -o proiect -lstdc++
CMD ["./proiect"]
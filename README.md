# Analyze Market Movements Using Present Data

A console-based **Stock Market Information System** developed in C++ that fetches real-time stock data using the Finnhub API.

## Features

- **Latest Stock News** – Retrieve recent company news for any stock symbol
- **Live Stock Price** – View current price, open, high, low, and previous close
- **Company Profile** – Get detailed company information (name, industry, market cap, IPO date, etc.)
- **Search History** – Automatically saves and displays previously searched symbols
- **Watchlist** – Add, view, and remove stocks from a personal watchlist
- Colored console interface for better readability

## Technologies Used

- **Language**: C++
- **API**: [Finnhub](https://finnhub.io/) Stock API
- **Libraries**:
  - [libcurl](https://curl.se/libcurl/) – HTTP requests
  - [nlohmann/json](https://github.com/nlohmann/json) – JSON parsing
- **Storage**: Plain text files (`history.txt`, `watchlist.txt`)

## Project Structure

## Prerequisites

- C++ compiler (g++ recommended)
- libcurl
- nlohmann/json library
- Finnhub API key (free tier available at [finnhub.io](https://finnhub.io/))

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/yashrajrwt/Analyze-Market-Movements-Using-Present-Data.git
   cd Analyze-Market-Movements-Using-Present-Data

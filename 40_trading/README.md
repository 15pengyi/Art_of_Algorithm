# Trading

## Books

[Way of the Turtle: The Secret Methods that Turned Ordinary People into Legendary Traders](https://weread.qq.com/web/bookDetail/a7f3237059b445a7fe05e36)

* The Principles
  * Principle #1 - Trend Following：buying a close above a moving average
  * Principle #2 - Position Sizing：1% risk rule.
  * Principle #3 - Entry & Exit Rules
  * Principle #4 - Risk Management

* The Systems
  * System #1 - ATR Channel Breakout
  * System #2 - Bollinger Breakout
  * System #3 - Donchian Trend
  * System #4 - Donchian Trend with Time Exit
  * System #5 - Dual Moving Average
  * System #6 - Triple Moving Average

* Measures
  * CAGR -> RAR (Regressed Annual Return)
  * MAR ratio (annual return / largest drawdown) -> Robust Risk / Reward ratio (RAR /  length-adjusted average maximum drawdown)
  * Sharpe ratio (CAGR / the std. of the return) -> Robust Sharpe Ratio (RAR / the annualized std. of the return).

* Average True Range

$$
TR = \max \{(H - L), |H - C_p|, |L - C_p| \},\\
ATR(n) = \frac{(n-1) \times ATR(n-1) + TR(n)}{n}.
$$

* Unit

$$
Unit = \frac{\text{1\% of Account}}{ATR \times \text{Dollars per Point}}.
$$

[因子投资：方法与实践](https://weread.qq.com/web/bookDetail/a0532d80720439a9a055795)

[Quantitative Trading: How to Build Your Own Algorithmic Trading Business](https://weread.qq.com/web/bookDetail/183325e0811e1a570g013878)

[Python 量化交易](https://weread.qq.com/web/bookDetail/c6332ff07191463ac6344e4)

* Quant Developer: trading strategy module, event-driven module, others (network, system, database).
* Quant Researcher: trade size vs. frequency, key metrics (Sharpe ratio - overfitting, CAGR, Max drawdown), simulated test markets.
* Quantitative trader.

## Research

[Huatai Securities](https://inst.htsc.com/research)

* [华泰人工智能研究6周年回顾](https://inst.htsc.com/research/report?reportId=3810458132)
* [2022中国量化投资白皮书](https://bigquant.com/quantwhitepaper/2022)

## Engineering

Platform

* [qlib](https://github.com/microsoft/qlib)

Model

* [Stock-Prediction-Models](https://github.com/huseinzol05/Stock-Prediction-Models#data-explorations)

API

* [futu-api-doc](https://openapi.futunn.com/futu-api-doc/)

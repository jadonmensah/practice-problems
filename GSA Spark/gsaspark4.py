# GSA spark day 4
url = "https://www.gsa-spark.com/speedtest/86de9fa1-e913-483e-9442-64e4609d8396"
post_url = "https://www.gsa-spark.com/speedtest/86de9fa1-e913-483e-9442-64e4609d8396"
import requests
from bs4 import BeautifulSoup
soup = BeautifulSoup(requests.get(url).content, features="html.parser")
number1 = int(soup.find(id="number1").string)
number2 = int(soup.find(id="number2").string)

result = number1 + number2
response = requests.post(url, data={"answer" : result})
print(response.content)
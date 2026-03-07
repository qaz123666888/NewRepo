import requests

api_key = "sk-2937401854554d7b832fcbc00f5cb6af"

# 👇 这里改成你的文件路径（可以直接从文件夹地址栏复制）
file_path = r"C:\Users\14481\Desktop\文档.docx"  # 改成你的实际文件名

# 读取文件（不管是docx还是txt）
try:
    # 如果是文本文件
    with open(file_path, "r", encoding="utf-8") as f:
        text = f.read()
except:
    # 如果是docx需要装库，先提示
    print("请把文件另存为.txt格式，或用网页版")
    exit()

response = requests.post(
    "https://api.deepseek.com/chat/completions",
    headers={"Authorization": f"Bearer {api_key}"},
    json={
        "model": "deepseek-chat",
        "messages": [{"role": "user", "content": f"总结：{text[:3000]}"}]
    }
)

print(response.json()["choices"][0]["message"]["content"])
input("按回车退出...")
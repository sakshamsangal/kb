import os
import shutil
from typing import List
import uvicorn
from fastapi import UploadFile, File
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
from fastapi.staticfiles import StaticFiles

base_path = ''
app = FastAPI()

script_dir = os.path.dirname(__file__)
st_abs_file_path = os.path.join(script_dir, "static/")
app.mount("/static", StaticFiles(directory=st_abs_file_path), name="static")


class MyItem(BaseModel):
    fn: str
    data: str


class MyPath(BaseModel):
    path: str


app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


def path_to_dict(path, xpath):
    d = {'name': os.path.basename(path)}
    if os.path.isdir(path):
        d['type'] = "dir"
        d['children'] = [path_to_dict(os.path.join(path, x), xpath + '/' + d['name']) for x in os.listdir(path)]
    else:
        d['type'] = "file"
        d['xpath'] = xpath
    return d




@app.post("/see-file")
async def see_file(item: MyPath):
    global base_path
    base_path = item.path.rsplit('/', 1)[0]
    print(base_path)
    x = path_to_dict(item.path, '')
    # with open('data.json', 'w') as f:
    #     json.dump(x, f)
    return x


@app.post("/files")
async def create_upload_file(file: List[UploadFile] = File(...)):
    for x in file:
        with open(f'{x.filename}', 'wb') as buffer:
            shutil.copyfileobj(x.file, buffer)
    return {'status': 'True'}


@app.post("/save")
async def save(item: MyItem):
    if item.fn == '':
        return {'status': 'False'}
    else:
        x = item.fn.rsplit('/', 1)[0]
        os.makedirs(f'{x}', exist_ok=True)
        with open(f'{base_path}{item.fn}', 'w') as f:
            f.write(item.data)
        return {'status': 'True'}


@app.post("/view")
async def view(item: MyPath):
    with open(f'{base_path}{item.path}', 'r') as f:
        x = f.read()
    return {'data': x}


if __name__ == "__main__":
    uvicorn.run("main:app", host="127.0.0.1", port=5000, log_level="info", reload=True)

from flask import Flask, redirect, request, url_for

app = Flask("example")


@app.route("/unsafe")
def usafe():
    url = request.args["url"]
    return redirect(url) # Noncompliant


@app.route("/safe")
def safe():
    url = request.args["url"]
    return redirect(url_for(url))

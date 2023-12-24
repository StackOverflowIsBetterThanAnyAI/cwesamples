from flask import Flask, request, render_template_string, abort

app = Flask(__name__)

# Liste des ID d'utilisateurs autorisés
AUTHORIZED_USER_IDS = {
    '123': 'john',
    '456': 'thomas'
}

@app.route('/unsafe')
def unsafe():
    user_id = request.args.get('user_id')
    # Supposons que le modèle suivant est utilisé pour afficher le profil de l'utilisateur
    template = """
    <html>
    <head><title>Profil</title></head>
    <body>
        <h1>Profil de l'utilisateur</h1>
        <p>ID utilisateur: {{ user_id }}</p>
        <p>Autres détails confidentiels...</p>
    </body>
    </html>
    """

    return render_template_string(template, user_id=user_id)


@app.route('/safe')
def safe():
    user_id = request.args.get('user_id')

    # Vérifier si l'utilisateur est autorisé à accéder à ce profil
    if user_id not in AUTHORIZED_USER_IDS.keys():
        # Si l'utilisateur n'est pas autorisé, renvoyer une erreur HTTP 403 Forbidden
        abort(403)

    # Si l'utilisateur est autorisé, afficher le profil
    template = """
    <html>
    <head><title>Profil</title></head>
    <body>
        <h1>Profil de l'utilisateur</h1>
        <p>Utilisateur : {{ user_name }}</p>
        <p>Autres détails confidentiels...</p>
    </body>
    </html>
    """

    return render_template_string(template, user_name=AUTHORIZED_USER_IDS['user_id'])


if __name__ == '__main__':
    app.run(debug=True)

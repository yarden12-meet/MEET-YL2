# always remember to import your models so you can use them
from models import Movie, Comment

from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render

def movie_list(request):
    list_of_all_movies = Movie.objects.all()
    context = {'movies_list': list_of_all_movies}
    # when you render, always pass a context as a dictionary
    # the way it is written here, movies_list.html can now
    # use a variable called "movies_list"
    return render(request, 'movies/movies_list.html', context)

# an example of how to process form submission
def add_movie(request):
    newmovie = Movie(title=request.POST['movie_title'])
    # when making new objects, always remember to save them
    newmovie.save()
    return HttpResponseRedirect('/movies')

def movie(request, movie_id):
    current_movie = Movie.objects.filter(pk = movie_id)[0]
    commentslist=Comment.objects.filter(movie=current_movie)
    context = {'movie':current_movie, 'comments':commentslist}
    return render(request, 'movies/movie.html', context)

def add_comment(request, movie_id):
    currentmovie=Movie.objects.filter(pk = movie_id)[0]
    newcomment = Comment(text=request.POST['comment_text'],movie=currentmovie)
    newcomment.save()
    return HttpResponseRedirect('/movies/'+movie_id)
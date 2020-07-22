#ifndef MOVIE_H
#define MOVIE_H
#include "imovie.h"

class Movie : public IMovie {
public:
 Movie(const std::string& movie_index,
       const std::string& movie_name,
       const std::string& movie_release_type);

 const std::string& name() const override;

 const std::string& release_type() const override;

 const std::string& index() const override;

 static std::unique_ptr<Movie> createFromLine(const std::string& line);
private:
 const std::string index_;
 const std::string name_;
 const std::string release_type_;
};
#endif // MOVIE_H

# https://gist.github.com/pocketWashburn
module Jekyll
  class PostPublisher < Generator
    safe false
  
    def replace(filepath, regexp, *args, &block)
      content = File.read(filepath).gsub(regexp, *args, &block)
      File.open(filepath, 'wb') { |file| file.write(content) }
    end
	  
    def generate(site)
      @files = Dir["#{site.source}/_publish/*"]
      @files.each_with_index { |f,i| 
        now = DateTime.now.strftime("%Y-%m-%d %H:%M:%S")
        replace(f, /^date: unpublished/mi) { |match| "date: \"" + now + "\"" }
        replace(f, /^date: 0000-01-01/mi) { |match| "date: \"" + now + "\"" }
        now = Date.today.strftime("%Y-%m-%d")
        File.rename(f, "#{site.source}/_posts/#{now}-#{File.basename(f)}") 
      }
    end
  end
end

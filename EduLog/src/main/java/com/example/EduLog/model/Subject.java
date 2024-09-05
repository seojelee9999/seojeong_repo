package com.example.EduLog.model;

import jakarta.persistence.*;
import java.util.Set;
@Entity
public class Subject {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    @OneToMany(mappedBy = "subject")
    private Set<SubSubject> subSubjects;

    // Getters and Setters

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Set<SubSubject> getSubSubjects() {
        return subSubjects;
    }

    public void setSubSubjects(Set<SubSubject> subSubjects) {
        this.subSubjects = subSubjects;
    }
}
